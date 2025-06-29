/* Copyright Kees Goossens 2023 */
/* Thread-safe FIFO library using pthread mutexes */

#ifndef _FIFO_MULTITHREADED_H_
#define _FIFO_MULTITHREADED_H_

#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>

typedef struct {
#ifdef MULTITHREADED
  pthread_mutex_t mut;
  pthread_cond_t new_space; // in the end, not any faster
  pthread_cond_t new_token;
#endif
  uint32_t nr_tokens;
  uint32_t token_size; // measured in bytes
  void * tokens;
  uint64_t wc;
  uint64_t rc;
  uint16_t tc; // tokens claimed
  uint16_t sc; // spaces claimed
} fifo_t;

extern fifo_t * fifo_init(fifo_t * const fifo_admin, void * const token_buffer, uint32_t const nr_tokens, uint32_t const token_size);
extern void fifo_destroy(fifo_t * const fifo_admin);
extern bool fifo_initialized(fifo_t * const fifo_admin);
extern void fifo_print_status(fifo_t * const fifo_admin);
// use fifo_spaces/tokens to poll, for non-blocking behaviour
// fifo_spaces/tokens returns the number of spaces/tokens that can still be claimed
extern uint32_t fifo_spaces(fifo_t * const fifo_admin);
extern uint32_t fifo_tokens(fifo_t * const fifo_admin);
extern void * fifo_claim_space(fifo_t * const fifo_admin);
extern void fifo_release_token(fifo_t * const fifo_admin);
extern void fifo_release_tokens(fifo_t * const fifo_admin, uint16_t const tokens);
extern void * fifo_claim_token(fifo_t * const fifo_admin);
extern void fifo_release_space(fifo_t * const fifo_admin);
extern void fifo_release_spaces(fifo_t * const fifo_admin, uint16_t const spaces);
// write/read = claim + release
// can only write/read when no spaces/tokens have been claimed, to avoid confusion
extern void fifo_write_token(fifo_t * const fifo_admin, void const * const token_to_write);
extern void fifo_read_token(fifo_t * const fifo_admin, void * const new_token);

#endif
