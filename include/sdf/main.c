/* Copyright Kees Goossens, Ingo Sander 2023 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "sdf.h"
#include "actors.h"

#ifdef COMPSOC
#include "xil_printf.h"
#define printf xil_printf
// note that xil_printf doesn't print double/float
#include "../shared_memories/vep_shared_memory_regions.h"
#define SHARED_MEM vep_memshared0_shared_region
#endif

int main(void) {
#define NRACTORS 3
#define NRCHANNELS 4
#define SOLENGTH 5
  bool const debug = true;
  uint32_t const nr_channels = NRCHANNELS;
  uint32_t const nr_actors = NRACTORS;
  uint32_t const static_order_schedule_length = SOLENGTH;
  // definition of the sdf graph
  sdf_channel_def_t * channels = NULL; // calloc'd when NULL
  sdf_actor_def_t * actors = NULL; // calloc'd when NULL
                                   // set all entries to undefined, so user doesn't have to do this
  (void) sdf_create_graph_data_structure (nr_channels, nr_actors, &channels, &actors);
  int a = 0;
  int ch = 0;

  ////////// USER INPUT STARTS HERE //////////
  actor_id_t const static_order_schedule[SOLENGTH] = { 0, 1, 2, 1, 2 };
  // channel 0
  channels[ch].src_actor = 0;
  channels[ch].dst_actor = 1;
  channels[ch].nr_tokens = 4;
  channels[ch].token_size = sizeof(uint32_t);
  channels[ch].nr_initial_tokens = 0;
#ifdef COMPSOC
  channels[ch].token_buffer = (void *) SHARED_MEM->token_buffer0;
  // #else NULL by default and then will be malloc'd
  // TODO: should really make .channel volatile
  channels[ch].channel = (sdf_channel_t *) &SHARED_MEM->channel0;
  // #else NULL by default and then will be malloc'd
  if (sizeof(SHARED_MEM->token_buffer0) != channels[ch].nr_tokens * channels[ch].token_size) {
    printf("configuration error: channel0's token buffer is %d bytes != %d * %d\n",
        sizeof(SHARED_MEM->token_buffer0), channels[ch].nr_tokens, channels[ch].token_size);
    exit(EXIT_FAILURE);
  }
#endif
  channels[ch].id = 0;
  ch++;
  // channel 1
  channels[ch].src_actor = 1;
  channels[ch].dst_actor = 2;
  channels[ch].nr_tokens = 2;
  channels[ch].token_size = 70*sizeof(uint8_t);
  channels[ch].nr_initial_tokens = 0;
#ifdef COMPSOC
  channels[ch].token_buffer = (void *) SHARED_MEM->token_buffer1;
  channels[ch].channel = (sdf_channel_t *) &SHARED_MEM->channel1;
  if (sizeof(SHARED_MEM->token_buffer1) != channels[ch].nr_tokens * channels[ch].token_size) {
    printf("configuration error: channel1's token buffer is %d bytes != %d * %d\n",
        sizeof(SHARED_MEM->token_buffer1), channels[ch].nr_tokens, channels[ch].token_size);
    exit(EXIT_FAILURE);
  }
#endif
  channels[ch].id = 1;
  ch++;
  // channel 2
  channels[ch].src_actor = 2;
  channels[ch].dst_actor = 1;
  channels[ch].nr_tokens = 4;
  channels[ch].token_size = sizeof(double);
  channels[ch].nr_initial_tokens = 2;
  double const initial_tokens21 = 99.0;
  double const initial_tokens22 = 98.0;
  void * initial_tokens2[] = { (void *) & initial_tokens21, (void *) & initial_tokens22 };
  channels[ch].initial_tokens = initial_tokens2;
#ifdef COMPSOC
  channels[ch].token_buffer = (void *) SHARED_MEM->token_buffer2;
  channels[ch].channel = (sdf_channel_t *) &SHARED_MEM->channel2;
  if (sizeof(SHARED_MEM->token_buffer2) != channels[ch].nr_tokens * channels[ch].token_size) {
    printf("configuration error: channel2's token buffer is %d bytes != %d * %d\n",
        sizeof(SHARED_MEM->token_buffer2), channels[ch].nr_tokens, channels[ch].token_size);
    exit(EXIT_FAILURE);
  }
#endif
  channels[ch].id = 2;
  ch++;
  // channel 3
  channels[ch].src_actor = 0;
  channels[ch].dst_actor = 0;
  channels[ch].nr_tokens = 1; // self edge with minimal buffering (must be copy)
  channels[ch].copy_tokens = true;
  channels[ch].token_size = sizeof(uint32_t);
  channels[ch].nr_initial_tokens = 1;
  uint32_t const initial_tokens31 = 10;
  void * initial_tokens3[] = { (void *) & initial_tokens31, };
  channels[ch].initial_tokens = initial_tokens3;
#ifdef COMPSOC
  channels[ch].token_buffer = (void *) SHARED_MEM->token_buffer3;
  if (sizeof(SHARED_MEM->token_buffer3) != channels[ch].nr_tokens * channels[ch].token_size) {
    printf("configuration error: channel3's token buffer is %d bytes != %d * %d\n",
        sizeof(SHARED_MEM->token_buffer3), channels[ch].nr_tokens, channels[ch].token_size);
    exit(EXIT_FAILURE);
  }
  channels[ch].channel = (sdf_channel_t *) &SHARED_MEM->channel3;
#endif
  channels[ch].id = 3;
  ch++;
  // actor 0
  actors[a].nr_input_tokens[0] = 1;
  actors[a].nr_output_tokens[0] = 2;
  actors[a].nr_output_tokens[1] = 1;
  actors[a].input_channel_ids[0] = 3;
  actors[a].output_channel_ids[0] = 0;
  actors[a].output_channel_ids[1] = 3;
  actors[a].actor_function = actor0_function;
  actors[a].id = 0;
  a++;
  // actor 1
  actors[a].nr_input_tokens[0] = 1;
  actors[a].nr_input_tokens[1] = 1;
  actors[a].nr_output_tokens[0] = 1;
  actors[a].input_channel_ids[0] = 0;
  actors[a].input_channel_ids[1] = 2;
  actors[a].output_channel_ids[0] = 1;
  actors[a].actor_function = actor1_function;
  actors[a].id = 1;
  a++;
  // actor 2
  actors[a].nr_input_tokens[0] = 1;
  actors[a].nr_output_tokens[0] = 1;
  actors[a].input_channel_ids[0] = 1;
  actors[a].output_channel_ids[0] = 2;
  actors[a].actor_function = actor2_function;
  actors[a].id = 2;
  a++;
  ////////// USER INPUT FINISHES HERE //////////


  ////////// create channels & actors

#ifdef COMPSOC
  // actor_args must be visible to all actors, hence map in shared memory
  // TODO: fix volatile
  sdf_actor_args_t * actor_args = (sdf_actor_args_t *) SHARED_MEM->actor_args;
#else
  sdf_actor_args_t * actor_args = NULL;
#endif

  sdf_create_run_time_data_structures (nr_channels, nr_actors, channels, actors, &actor_args);


  ////////// run forever

#if COMPSOC && ACTOR0
  (void) sdf_actor_start (&actor_args[a]);
  sdf_actor(&actor_args[static_order_schedule[0]]);
  sdf_actor_stop (&actor_args[a]);
#endif
#if COMPSOC && ACTOR1
  (void) sdf_actor_start (&actor_args[a]);
  sdf_actor(&actor_args[static_order_schedule[1]]);
  sdf_actor_stop (&actor_args[a]);
#endif
#if COMPSOC && ACTOR2
  (void) sdf_actor_start (&actor_args[a]);
  sdf_actor(&actor_args[static_order_schedule[2]]);
  sdf_actor_stop (&actor_args[a]);
#endif
#if COMPSOC && ACTOR3
  (void) sdf_actor_start (&actor_args[a]);
  sdf_actor(&actor_args[static_order_schedule[3]]);
  sdf_actor_stop (&actor_args[a]);
#endif

#if (!COMPSOC) && MULTITHREADED
  pthread_t ids[NRACTORS];
  for (int a = 0; a < nr_actors; a++) {
    if (debug) printf("info: start actor %d\n", a);
    ids[a] = sdf_actor_start (&actor_args[a]);
  }
  while(true) {
    system("sleep 3");
    for (int a = 0; a < nr_actors; a++) {
      if (debug) printf("info: disable actor %d\n", a);
      sdf_actor_disable (&actor_args[a]);
    }
    printf("(c)ontinue or (s)top?");
    char c;
    (void) scanf(" %c", &c);
    if (c == 's') break;
    for (int a = 0; a < nr_actors; a++) {
      if (debug) printf("info: enable actor %d\n", a);
      sdf_actor_enable (&actor_args[a]);
    }
  }
  for (int a = 0; a < nr_actors; a++) {
    if (debug) printf("info: stop actor %d\n", a);
    sdf_actor_stop (&actor_args[a]);
  }
  printf("'y' to kill actors ");
  char c;
  (void) scanf(" %c", &c);
  for (int a = 0; a < nr_actors; a++) {
    if (debug) printf("info: kill actor %d\n", a);
    pthread_kill(ids[a], SIGINT);
    // should join instead
    //pthread_join(ids[a], NULL);
  }
#endif

#ifdef SINGLETHREADED
  if (false) {
    // each actor fires as many times as possible in a sequential order
    bool fired = false;
    do {
      fired = false;
      for (int s = 0; s < nr_actors; s++) {
        sdf_actor_args_t * a = &actor_args[s];
        while (sdf_actor_can_fire(a) == true) {
          sdf_actor_single_firing (a);
          fired = true;
        }
      }
    } while (fired);
  } else {
    // static order schedule
    for (int a = 0; a < nr_actors; a++) {
      if (debug) printf("info: start actor %d\n", a);
      sdf_actor_start (&actor_args[a]);
      sdf_actor_enable (&actor_args[a]);
    }
    for (int i=0; i<20; i++) {
#ifndef COMPSOC
      if (i == 10) {
        for (int a = 0; a < nr_actors; a++) {
          if (debug) printf("info: disable actor %d\n", a);
          sdf_actor_disable (&actor_args[a]);
        }
        printf("(c)ontinue or (s)top?");
        char c;
        (void) scanf(" %c", &c);
        if (c == 's') {
          // clean up after the main loop
          break;
        }
        for (int a = 0; a < nr_actors; a++) {
          if (debug) printf("info: enable actor %d\n", a);
          sdf_actor_enable (&actor_args[a]);
        }
      }
#endif

      for (int s = 0; s < static_order_schedule_length; s++) {
        sdf_actor_args_t * a = &actor_args[static_order_schedule[s]];
        //printf("schedule actor %d\n", a->id);
        //sdf_running_actor_print_status (a);
        // the complex deadlock checking can also be done by just checking sdf_actor_can_fire,
        // but then you don't get the precise diagnostics
        for (int c = 0; c < MAXCHANNELS && a->input_channels[c] != NULL; c++) {
          if (sdf_channel_tokens(a->input_channels[c]) < a->nr_input_tokens[c]) {
            printf("error: deadlock in schedule: %d tokens in input channel #%d < %d required for actor %d\n",
                sdf_channel_tokens(a->input_channels[c]), c, a->nr_input_tokens[c], a->id);
            return EXIT_FAILURE;
          }
        }
        for (int c = 0; c < MAXCHANNELS && a->output_channels[c] != NULL; c++) {
          // need to take into accound that input tokens are removed from self edges before output
          int d, self_edge = 0;
          for (d = 0; d < MAXCHANNELS && a->input_channels[d] != NULL; d++) {
            if (a->input_channels[d] == a->output_channels[c]) {
              self_edge = a->nr_input_tokens[d];
              break;
            }
          }
          if (channels[actors[a->id].output_channel_ids[c]].copy_tokens == false && sdf_channel_spaces(a->output_channels[c]) < a->nr_output_tokens[c]) {
            printf("error: deadlock in schedule: %d spaces in non-copy-token output channel #%d < %d required for actor %d\n",
                sdf_channel_spaces(a->output_channels[c]), c, a->nr_output_tokens[c], a->id);
            if (sdf_channel_spaces(a->output_channels[c]) + self_edge >= a->nr_output_tokens[c]) {
              printf("a reason for this can be that the channel does not copy tokens and therefore doesn't remove tokens from the channels before firing\n");
            }
            return EXIT_FAILURE;
          }
          if (channels[actors[a->id].output_channel_ids[c]].copy_tokens == true && sdf_channel_spaces(a->output_channels[c]) + self_edge < a->nr_output_tokens[c]) {
            printf("error: deadlock in schedule: %d spaces in copy-token output channel #%d < %d required for actor %d\n",
                sdf_channel_spaces(a->output_channels[c]), c, a->nr_output_tokens[c], a->id);
            return EXIT_FAILURE;
          }
        }
        sdf_actor_single_firing (a);
      }
    }
    for (int a = 0; a < nr_actors; a++) {
      if (debug) printf("info: stop actor %d\n", a);
      sdf_actor_stop (&actor_args[a]);
    }
  }
#endif
  return EXIT_SUCCESS;
}
