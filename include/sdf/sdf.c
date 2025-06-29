/* Copyright Kees Goossens 2023 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "sdf.h"

#ifdef COMPSOC
#include "xil_printf.h"
#define printf xil_printf
#endif

// this is the same for both single- and multi-threaded implementations

sdf_channel_t * sdf_create_channel (sdf_channel_t * const channel, void * const token_buffer, uint32_t const nr_tokens, uint32_t const token_size)
{
  return (sdf_channel_t *) fifo_init (channel, token_buffer, nr_tokens, token_size);
}

uint32_t sdf_channel_spaces (sdf_channel_t * const channel) { return fifo_spaces (channel); }
uint32_t sdf_channel_tokens (sdf_channel_t * const channel) { return fifo_tokens (channel); }
void * sdf_claim_space(fifo_t * const channel) { return fifo_claim_space (channel); }
void sdf_release_token(fifo_t * const channel) { fifo_release_token (channel); }
void sdf_release_tokens(fifo_t * const channel, uint32_t const tokens) { fifo_release_tokens (channel, tokens); }
void * sdf_claim_token(fifo_t * const channel) { return fifo_claim_token (channel); }
void sdf_release_space(fifo_t * const channel) { fifo_release_space (channel); }
void sdf_release_spaces(fifo_t * const channel, uint32_t const spaces) { fifo_release_spaces (channel, spaces); }
void sdf_read_token (sdf_channel_t * const channel, void * const new_token) { fifo_read_token (channel, new_token); }
void sdf_write_token (sdf_channel_t * const channel, void const * const token_to_write) { fifo_write_token (channel, token_to_write); }

void sdf_channel_print_status (sdf_channel_def_t const * const args)
{
  printf("channel id=%d src=%d dst=%d size=%d #tok=%d #init=%d buf=%p cp=%d\n",
      args->id, args->src_actor, args->dst_actor, args->token_size, args->nr_tokens, args->nr_initial_tokens, args->token_buffer, args->copy_tokens);
  fifo_print_status (args->channel);
}

void sdf_actor_print_status (sdf_actor_def_t const * const args)
{
  printf("actor id=%d inchans=", args->id);
  for (int c = 0; c < MAXCHANNELS && args->input_channel_ids[c] >= 0; c++) printf("%d,",args->input_channel_ids[c]);
  printf(" outchans=");
  for (int c = 0; c < MAXCHANNELS && args->output_channel_ids[c] >= 0; c++) printf("%d,",args->output_channel_ids[c]);
  printf(" inrates=");
  for (int c = 0; c < MAXCHANNELS && args->input_channel_ids[c] >= 0; c++) printf("%d,",args->nr_input_tokens[c]);
  printf(" outrates=");
  for (int c = 0; c < MAXCHANNELS && args->output_channel_ids[c] >= 0; c++) printf("%d,",args->nr_output_tokens[c]);
  printf("\n");
}

void sdf_running_actor_print_status (sdf_actor_args_t const * const args)
{
  printf("--- actor id=%d stop=%d disable=%d disabled=%d\n", 
      args->id, args->stop_actor, args->disable_actor, args->actor_disabled);
  for (int c = 0; c < MAXCHANNELS && args->input_channels[c] != NULL; c++) {
    printf(" inch=%d cp=%d ", c, args->copy_input_channel[c]);
    fifo_print_status (args->input_channels[c]);
  }
  for (int c = 0; c < MAXCHANNELS && args->output_channels[c] != NULL; c++) {
    printf("outch=%d cp=%d ", c, args->copy_output_channel[c]);
    fifo_print_status (args->output_channels[c]);
  }
  printf("intokens ");
  for (int t = 0; t < MAXTOKENS; t++) printf(" %p", args->input_tokens[t]);
  printf("\nouttokens");
  for (int t = 0; t < MAXTOKENS; t++) printf(" %p", args->output_tokens[t]);
  printf("\n");
}

// call sdf_create_graph_data_structure to (optionally) malloc data structures and initialise them
// then define the channels & actors in the given data structure
// then call sdf_create_run_time_data_structures to create the run-time data structures
// return true on success, exit on failure (since cannot recover anyway)
bool sdf_create_graph_data_structure (uint32_t nr_channels, uint32_t nr_actors, sdf_channel_def_t * * channels, sdf_actor_def_t * * actors)
{
  if (channels == NULL || actors == NULL) {
    printf("error: sdf_create_graph_data_structure: invalid input arguments\n");
    exit(EXIT_FAILURE);
  }
  if (*channels == NULL) *channels = (sdf_channel_def_t *) calloc (nr_channels, sizeof(sdf_channel_def_t));
  if (*channels == NULL) {
    printf("error: cannot create channels\n");
    exit(EXIT_FAILURE);
  }
  if (*actors == NULL) *actors = (sdf_actor_def_t *) calloc (nr_actors, sizeof(sdf_actor_def_t));
  if (*actors == NULL) {
    printf("error: cannot create actors\n");
    exit(EXIT_FAILURE);
  }
  // set all entries to undefined, so user doesn't have to do this
  for (int c = 0; c < MAXCHANNELS; c++) {
    (*channels)[c].id = NO_CHANNEL;
  }
  for (int a = 0; a < nr_actors; a++) {
    (*actors)[a].id = NO_ACTOR;
    for (int c = 0; c < MAXCHANNELS; c++) {
      (*actors)[a].input_channel_ids[c] = NO_CHANNEL;
      (*actors)[a].output_channel_ids[c] = NO_CHANNEL;
    }
  }
  return true;
}

// return true on success, exit on failure (since cannot recover anyway)
bool sdf_create_run_time_data_structures (uint32_t nr_channels, uint32_t nr_actors, sdf_channel_def_t * const channels, sdf_actor_def_t * const actors, sdf_actor_args_t * * actor_args)
{
  bool const debug = true;
  if (*actor_args == NULL) *actor_args = (sdf_actor_args_t *) calloc (nr_actors, sizeof(sdf_actor_args_t));
  if (*actor_args == NULL) {
    printf("error: cannot create actor_args\n");
    exit(EXIT_FAILURE);
  }
#if (!COMPSOC) || (COMPSOC && SINGLETHREADED) || (COMPSOC && MULTITHREADED && ACTOR0)
  if (debug) printf("-----\n");
  for (int c = 0; c < nr_channels; c++) {
    if (debug) printf("info: create channel %d\n", c);
    // validate that channel with id c is at position c in the array; we rely on this later
    if (channels[c].id != c) {
      printf("error: channels[%d] == %d != %d\n", c, channels[c].id, c);
      exit(EXIT_FAILURE);
    }
    if (channels[c].channel == NULL) {
      channels[c].channel = (sdf_channel_t *) malloc (sizeof(sdf_channel_t));
    }
    if (channels[c].channel == NULL) {
      printf("error: cannot create channel %d's channel struct\n", c);
      exit(EXIT_FAILURE);
    }
    if (channels[c].token_buffer == NULL) {
      channels[c].token_buffer = (void *) malloc (channels[c].nr_tokens * channels[c].token_size);
    }
    if (channels[c].token_buffer == NULL) {
      printf("error: cannot create channel %d's token buffer\n", c);
      exit(EXIT_FAILURE);
    }
    if (sdf_create_channel (channels[c].channel, channels[c].token_buffer, channels[c].nr_tokens, channels[c].token_size) == NULL) {
      printf("error: cannot initialise channel %d\n", c);
      exit(EXIT_FAILURE);
    }
    for (int i = 0; i < channels[c].nr_initial_tokens; i++) {
      if (debug) printf("info: channel %d initial token %d\n", c, i);
      sdf_write_token (channels[c].channel, channels[c].initial_tokens[i]);
    }
  }

  for (int a = 0; a < nr_actors; a++) {
    if (debug) printf("info: create actor %d\n", a);
    // validate that actor with id c is at position c in the array; we rely on this later
    if (actors[a].id != a) {
      printf("error: actors[%d] == %d != %d\n", a, actors[a].id, a);
      exit(EXIT_FAILURE);
    }
    (*actor_args)[a].id = actors[a].id;
    (*actor_args)[a].actor_function = actors[a].actor_function;
    for (int c = 0; c < MAXCHANNELS; c++) {
      (*actor_args)[a].nr_self_tokens[c] = 0;
      if (actors[a].input_channel_ids[c] < 0) {
        (*actor_args)[a].nr_input_tokens[c] = 0;
        (*actor_args)[a].input_token_size[c] = 0;
        (*actor_args)[a].input_channels[c] = NULL;
        (*actor_args)[a].copy_input_channel[c] = false;
      }
      else {
        (*actor_args)[a].nr_input_tokens[c] = actors[a].nr_input_tokens[c];
        (*actor_args)[a].input_token_size[c] = channels[actors[a].input_channel_ids[c]].token_size;
        (*actor_args)[a].input_channels[c] = channels[actors[a].input_channel_ids[c]].channel;
        if ((*actor_args)[a].input_channels[c]  == NULL) {
          printf("error: %d'th input channel %d of actor %d is NULL\n", c, actors[a].input_channel_ids[c], a);
          exit(EXIT_FAILURE);
        }
        (*actor_args)[a].copy_input_channel[c] = channels[actors[a].input_channel_ids[c]].copy_tokens;
      }
      if (actors[a].output_channel_ids[c] < 0) {
        (*actor_args)[a].nr_output_tokens[c] = 0;
        (*actor_args)[a].output_token_size[c] = 0;
        (*actor_args)[a].output_channels[c] = NULL;
        (*actor_args)[a].copy_output_channel[c] = false;
      }
      else {
        (*actor_args)[a].nr_output_tokens[c] = actors[a].nr_output_tokens[c];
        (*actor_args)[a].output_token_size[c] = channels[actors[a].output_channel_ids[c]].token_size;
        (*actor_args)[a].output_channels[c] = channels[actors[a].output_channel_ids[c]].channel;
        if ((*actor_args)[a].output_channels[c]  == NULL) {
          printf("error: %d'th output channel %d of actor %d is NULL\n", c, actors[a].output_channel_ids[c], a);
          exit(EXIT_FAILURE);
        }
        (*actor_args)[a].copy_output_channel[c] = channels[actors[a].output_channel_ids[c]].copy_tokens;
      }
    }
    // compute the number of tokens that will be removed from this self-edge output channel every firing
    for (int c = 0; c < MAXCHANNELS && actors[a].output_channel_ids[c] >= 0; c++) {
      (*actor_args)[a].nr_self_tokens[c] = 0;
      for (int d = 0; d < MAXCHANNELS && (*actor_args)[a].input_channels[d] != NULL; d++) {
        if ((*actor_args)[a].input_channels[d] == (*actor_args)[a].output_channels[c]) {
          if (channels[actors[a].output_channel_ids[c]].copy_tokens == true) {
            (*actor_args)[a].nr_self_tokens[c] = (*actor_args)[a].nr_input_tokens[d];
          }
          // else when not copying tokens then the space of self-edge input tokens is only released after firing
          /*
          //if (channels[actors[a].output_channel_ids[c]].nr_initial_tokens - (*actor_args)[a].nr_self_tokens[c] < (*actor_args)[a].nr_input_tokens[d]) {
            printf("warning: actor %d will deadlock: self edge chan=%d inchan#=%d #intok=%d, outchan#=%d #outtok=%d, #initial=%d\n",
                a, actors[a].output_channel_ids[c],
                d, (*actor_args)[a].nr_input_tokens[d],
                c, (*actor_args)[a].nr_output_tokens[c],
                channels[ actors[a].output_channel_ids[c]].nr_initial_tokens);
           printf("warning: either increase the number of initial tokens (%d) or make the channel copy tokens\n",
               (*actor_args)[a].nr_self_tokens[c]);
          //}
          */
          break;
        }
      }
    }
    // to avoid further indirections, all input tokens are linearised into a single array
    // e.g. channel 0 with 2 tokens, channel 1 with 1 token --> input_tokens = ch0tok0, ch0tok1, ch1tok0
    int nrintoks = 0;
    for (int c = 0; c < MAXCHANNELS && (*actor_args)[a].input_channels[c] != NULL; c++) {
      for (int t = 0; t < (*actor_args)[a].nr_input_tokens[c]; t++) {
        if ((*actor_args)[a].copy_input_channel[c] == false) {
          (*actor_args)[a].input_tokens[nrintoks] = NULL;
        } else {
          (*actor_args)[a].input_tokens[nrintoks] = (void *) malloc ((*actor_args)[a].input_token_size[c]);
        }
        if (++nrintoks > MAXTOKENS) {
          printf("error: input nrtokens=%d > MAXTOKENS=%d for actor %d\n", nrintoks, MAXTOKENS, a);
          exit(EXIT_FAILURE);
        }
      }
    }
    int nrouttoks = 0;
    for (int c = 0; c < MAXCHANNELS && (*actor_args)[a].output_channels[c] != NULL; c++) {
      for (int t = 0; t < (*actor_args)[a].nr_output_tokens[c]; t++) {
        if ((*actor_args)[a].copy_output_channel[c] == false) {
          (*actor_args)[a].output_tokens[nrouttoks] = NULL;
        } else {
          (*actor_args)[a].output_tokens[nrouttoks] = (void *) malloc ((*actor_args)[a].output_token_size[c]);
        }
        if (++nrouttoks > MAXTOKENS) {
          printf("error: output nrtokens=%d > MAXTOKENS=%d for actor %d\n", nrouttoks, MAXTOKENS, a);
          exit(EXIT_FAILURE);
        }
      }
    }
  }
  if (debug) {
    for (int c = 0; c < nr_channels; c++) sdf_channel_print_status (&channels[c]);
    for (int a = 0; a < nr_actors; a++) sdf_actor_print_status (&actors[a]);
    printf("-----\n");
  }
#endif
  return true;
}

// block until can fire, or until disabled or stopped
bool sdf_actor_can_fire (sdf_actor_args_t * const args)
{
  for (int c = 0; c < MAXCHANNELS && args->input_channels[c] != NULL; c++) {
    while (sdf_channel_tokens (args->input_channels[c]) < args->nr_input_tokens[c]) {
      if (args->stop_actor || args->disable_actor) return false;
    }
  }
  for (int c = 0; c < MAXCHANNELS && args->output_channels[c] != NULL; c++) {
    while (sdf_channel_spaces (args->output_channels[c]) + args->nr_self_tokens[c] < args->nr_output_tokens[c]) {
      if (args->stop_actor || args->disable_actor) return false;
    }
  }
  if (args->stop_actor || args->disable_actor) return false;
  return true;
}

void sdf_actor_single_firing (sdf_actor_args_t * const args)
{
  // first wait until all tokens & spaces are available, only then claim them
  // this allows a better handling of dis/enabling
  if (sdf_actor_can_fire (args) == false) return;
  //sdf_running_actor_print_status (args);

  // to avoid further indirections, all input/output tokens are linearised into a single array
  // e.g. channel 0 with 2 tokens, channel 1 with 1 token --> input_tokens = ch0tok0, ch0tok1, ch1tok0

  // uninterruptable firing
  int nrintoks = 0, nrouttoks = 0;
  for (int c = 0; c < MAXCHANNELS && args->input_channels[c] != NULL; c++) {
    for (int t = 0; t < args->nr_input_tokens[c]; t++) {
      if (args->copy_input_channel[c] == false) {
        args->input_tokens[nrintoks] = sdf_claim_token (args->input_channels[c]);
      } else {
        sdf_read_token (args->input_channels[c], args->input_tokens[nrintoks]);
      }
      nrintoks++;
    }
  }
  for (int c = 0; c < MAXCHANNELS && args->output_channels[c] != NULL; c++) {
    for (int t = 0; t < args->nr_output_tokens[c]; t++) {
      if (args->copy_output_channel[c] == false) {
        args->output_tokens[nrouttoks] = sdf_claim_space (args->output_channels[c]);
      }
      nrouttoks++;
    }
  }
  // each function knows how to interpret its channels and tokens
  args->actor_function (args->input_tokens, args->output_tokens);
  for (int c = 0; c < MAXCHANNELS && args->input_channels[c] != NULL; c++) {
    if (args->copy_input_channel[c] == false) {
      sdf_release_spaces (args->input_channels[c], args->nr_input_tokens[c]);
    }
  }
  nrouttoks = 0;
  for (int c = 0; c < MAXCHANNELS && args->output_channels[c] != NULL; c++) {
    if (args->copy_output_channel[c] == false) {
      sdf_release_tokens (args->output_channels[c], args->nr_output_tokens[c]);
      nrouttoks += args->nr_output_tokens[c];
    } else {
      for (int t = 0; t < args->nr_output_tokens[c]; t++) {
        sdf_write_token (args->output_channels[c], args->output_tokens[nrouttoks]);
        nrouttoks++;
      }
    }
  }
  //sdf_running_actor_print_status (args);
}

void sdf_actor (sdf_actor_args_t * const args)
{
  // wait until channels are initialised
  for (int c = 0; c < MAXCHANNELS && args->input_channels[c] != NULL; c++) {
    while (!fifo_initialized (args->input_channels[c])) {}
  }
  for (int c = 0; c < MAXCHANNELS && args->output_channels[c] != NULL; c++) {
    while (!fifo_initialized (args->output_channels[c])) {}
  }

  while (true) {
    while (!args->stop_actor && !args->disable_actor) sdf_actor_single_firing (args);
    printf("actor %d disabled\n", args->id);
    // actor suspends itself
    args->actor_disabled = 1;
    while (args->disable_actor || args->stop_actor) {}
    if (args->stop_actor) return;
    printf("actor %d enabled\n", args->id);
    // enable actor
    args->actor_disabled = 0;
  }
}

void * sdf_actor_thread (void * args)
{
  sdf_actor ((sdf_actor_args_t *) args);
  // the actor has been stopped
#ifdef MULTITHREADED
  // this doesn't seem to want to join with the main function
  pthread_exit(NULL);
#endif
  return NULL;
}

actor_thread_t sdf_actor_start (sdf_actor_args_t * const args)
{
#ifdef MULTITHREADED
  pthread_t tid;
  if (pthread_create (&tid, NULL, sdf_actor_thread, (void *) args)) {
    printf("error: cannot start actor %d\n", args->id);
    exit(EXIT_FAILURE);
  }
  args->stop_actor = 0;
  args->disable_actor = 0;
  args->actor_disabled = 0;
  return tid;
#endif
  args->stop_actor = 0;
  args->disable_actor = 0;
  args->actor_disabled = 0;
  return 0;
}

void sdf_actor_disable (sdf_actor_args_t * const args)
{
  args->disable_actor = 1;
}

void sdf_actor_enable (sdf_actor_args_t * const args)
{
  args->disable_actor = 0;
}

void sdf_actor_stop (sdf_actor_args_t * const args)
{
  args->disable_actor = 1;
#if MULTITHREADED
  while (!args->actor_disabled) {}
#endif
  args->stop_actor = 1;
  int nrintoks = 0;
  for (int c = 0; c < MAXCHANNELS && args->input_channels[c] != NULL; c++) {
    for (int t = 0; t < args->nr_input_tokens[c]; t++) {
      if (args->copy_input_channel[c] == true) {
        free (args->input_tokens[nrintoks]);
      }
      nrintoks++;
    }
  }
  int nrouttoks = 0;
  for (int c = 0; c < MAXCHANNELS && args->output_channels[c] != NULL; c++) {
    for (int t = 0; t < args->nr_output_tokens[c]; t++) {
      if (args->copy_output_channel[c] == true) {
        free (args->output_tokens[nrouttoks]);
      }
      nrouttoks++;
    }
  }
}
