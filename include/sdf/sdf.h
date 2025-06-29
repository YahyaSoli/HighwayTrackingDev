/* Copyright Kees Goossens 2023 */

#ifndef _SDF_H_
#define _SDF_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef COMPSOC
#include "fifo.h"
typedef uint32_t actor_thread_t;
#else
#ifdef SINGLETHREADED
#include "fifo.h"
typedef uint32_t actor_thread_t;
#endif
#ifdef MULTITHREADED
#include "fifo.h"
typedef pthread_t actor_thread_t;
#endif
#endif

typedef fifo_t sdf_channel_t;

extern sdf_channel_t * sdf_create_channel (sdf_channel_t * const channel, void * const token_buffer, uint32_t const nr_tokens, uint32_t const token_size);
extern uint32_t sdf_channel_spaces (sdf_channel_t * const channel);
extern uint32_t sdf_channel_tokens (sdf_channel_t * const channel);
extern void * sdf_claim_space(fifo_t * const fifo_admin);
extern void sdf_release_token(fifo_t * const fifo_admin);
extern void sdf_release_tokens(fifo_t * const fifo_admin, uint32_t const tokens);
extern void * sdf_claim_token(fifo_t * const fifo_admin);
extern void sdf_release_space(fifo_t * const fifo_admin);
extern void sdf_release_spaces(fifo_t * const fifo_admin, uint32_t const spaces);
extern void sdf_write_token (sdf_channel_t * const channel, void const * const token_to_write);
extern void sdf_read_token (sdf_channel_t * const channel, void * const new_token);

#define MAXCHANNELS 3 		  /* max # in/output channels per actor */
#define MAXTOKENS (MAXCHANNELS*3) /* max # in/output tokens for a single actor firing */

// types for user to define an SDF graph

#define NO_ACTOR (-1)
#define NO_CHANNEL (-1)
typedef int32_t actor_id_t;   // < 0 is undefined
typedef int32_t channel_id_t; // < 0 is undefined
typedef struct {
  channel_id_t id; // can have >1 channel between actors
  actor_id_t src_actor;
  actor_id_t dst_actor;
  uint32_t nr_tokens;
  uint32_t token_size;
  uint32_t nr_initial_tokens;
  void * * initial_tokens; // array of pointers to initial tokens

  // TODO this is mapping info -- move to a separata data structure?
  // TODO should be volatile (at least for MULTITHREADED & COMPSOC)
  void * token_buffer;     // malloc'd when NULL
  sdf_channel_t * channel; // malloc'd when NULL
  // use read/write instead of claim/release_space/token (default: false)
  // this is only required for self edges with nr_in/output_tokens equal
  // or without shared address space (e.g. DDS); the space required is then malloc'd
  bool copy_tokens;
} sdf_channel_def_t;

typedef struct {
  actor_id_t id;
  uint32_t nr_input_tokens[MAXCHANNELS];
  uint32_t nr_output_tokens[MAXCHANNELS];
  channel_id_t input_channel_ids[MAXCHANNELS];
  channel_id_t output_channel_ids[MAXCHANNELS];
  void (*actor_function) (void * const * const input_tokens, void * const * const output_tokens);
} sdf_actor_def_t;

// run-time types

typedef struct {
  // copied from actor/channel_def
  actor_id_t id;
  uint32_t nr_input_tokens[MAXCHANNELS];
  uint32_t nr_output_tokens[MAXCHANNELS];
  uint32_t nr_self_tokens[MAXCHANNELS];
  void (*actor_function) (void * const * const input_tokens, void * const * const output_tokens);
  uint32_t input_token_size[MAXCHANNELS];
  uint32_t output_token_size[MAXCHANNELS];
  // optimisation to avoid recomputing every firing
  sdf_channel_t * input_channels[MAXCHANNELS];
  sdf_channel_t * output_channels[MAXCHANNELS];
  bool copy_input_channel[MAXCHANNELS];
  bool copy_output_channel[MAXCHANNELS];
  // when copying tokens, malloc'd when starting actor & freed when stopping actor
  // TODO: allow this to specified as part of mapping of channel
  void * input_tokens[MAXTOKENS];
  void * output_tokens[MAXTOKENS];
  // asynchronous interactions with the actor to en/disable/start/stop
#ifdef COMPSOC
  uint32_t volatile stop_actor;       // actor (thread) exits when != 0
  uint32_t volatile disable_actor;    // actor only fires when disable_actor == 0
  uint32_t volatile actor_disabled;   // actors sets this to 1 to acknowledge it has seen disable_actor
#else
  _Atomic(uint32_t) stop_actor;       // actor (thread) exits when != 0
  _Atomic(uint32_t) disable_actor;    // actor only fires when disable_actor == 0
  _Atomic(uint32_t) actor_disabled;   // actors sets this to 1 to acknowledge it has seen disable_actor
#endif
} sdf_actor_args_t;

extern bool sdf_create_graph_data_structure (uint32_t nr_channels, uint32_t nr_actors, sdf_channel_def_t * * channels, sdf_actor_def_t * * actors);
extern bool sdf_create_run_time_data_structures (uint32_t nr_channels, uint32_t nr_actors, sdf_channel_def_t * const channels, sdf_actor_def_t * const actors, sdf_actor_args_t * * actor_args);
extern void sdf_channel_print_status (sdf_channel_def_t const * const args);
extern void sdf_actor_print_status (sdf_actor_def_t const * const args);
extern void sdf_running_actor_print_status (sdf_actor_args_t const * const args);
// block until can fire (and return true), or until disabled or stopped (and return false)
extern bool sdf_actor_can_fire (sdf_actor_args_t * const args);
extern void sdf_actor_single_firing (sdf_actor_args_t * const args);
extern void sdf_actor (sdf_actor_args_t * const args);
extern actor_thread_t sdf_actor_start (sdf_actor_args_t * const args);
extern void sdf_actor_enable (sdf_actor_args_t * const args);
// to avoid deadlock, after disabling, an actor stops before it fires
// i.e. reading its tokens & processing & writing its tokens
// if it has read a token then it will finish its firing
extern void sdf_actor_disable (sdf_actor_args_t * const args);
extern void sdf_actor_stop (sdf_actor_args_t * const args);

#endif
