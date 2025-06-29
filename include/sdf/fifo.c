/* Copyright Kees Goossens 2023 */
/* Thread-safe FIFO library using pthread mutexes */

#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <limits.h>
#include "fifo.h"

fifo_t * fifo_init(fifo_t * const fifo_admin, void * const token_buffer, uint32_t const nr_tokens, uint32_t const token_size)
{
  if (fifo_admin == NULL || token_buffer == NULL || nr_tokens < 1 || token_size < 1) exit(EXIT_FAILURE);
#ifdef MULTITHREADED
  pthread_mutex_init(&fifo_admin->mut, 0);
  pthread_cond_init(&fifo_admin->new_space, NULL);
  pthread_cond_init(&fifo_admin->new_token, NULL);
  pthread_mutex_lock(&fifo_admin->mut);
#endif
  fifo_admin->wc = 0;
  fifo_admin->rc = 0;
  fifo_admin->tc = 0;
  fifo_admin->sc = 0;
  fifo_admin->tokens = token_buffer;
  fifo_admin->token_size = token_size;
  fifo_admin->nr_tokens = nr_tokens;
#ifdef MULTITHREADED
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
  return fifo_admin;
}

void fifo_destroy(fifo_t * const fifo_admin)
{
  if (fifo_admin == NULL) exit(EXIT_FAILURE);
#ifdef MULTITHREADED
  pthread_mutex_lock(&fifo_admin->mut);
  pthread_cond_destroy(&fifo_admin->new_space);
  pthread_cond_destroy(&fifo_admin->new_token);
#endif
  fifo_admin->wc = 0;
  fifo_admin->rc = 0;
  fifo_admin->tc = 0;
  fifo_admin->sc = 0;
  fifo_admin->token_size = 0;
  fifo_admin->tokens = NULL;
  fifo_admin->nr_tokens = 0;
#ifdef MULTITHREADED
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
}

bool fifo_initialized(fifo_t * const fifo_admin)
{
  if (fifo_admin == NULL) exit(EXIT_FAILURE);
#ifdef MULTITHREADED
  pthread_mutex_lock(&fifo_admin->mut);
#endif
  uint32_t const r = (fifo_admin->nr_tokens > 0 ? true : false);
  // nr_tokens is the last field to be initialised and must be > 0
#ifdef MULTITHREADED
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
  return r;
}

void fifo_print_status(fifo_t * const fifo_admin)
{
  if (fifo_admin == NULL) exit(EXIT_FAILURE);
#ifdef MULTITHREADED
  pthread_mutex_lock(&fifo_admin->mut);
#endif
  uint64_t const wc = fifo_admin->wc;
  uint64_t const rc = fifo_admin->rc;
  uint32_t const diff = wc - rc;
  uint32_t const nrt = fifo_admin->nr_tokens;
  uint32_t const tc = fifo_admin->tc;
  uint32_t const sc = fifo_admin->sc;
  printf("toks=0x%8p d=%u sz=%u wc=%llu rc=%llu tc=%u sc=%u spaces=%u tokens=%u\n",
      fifo_admin->tokens, nrt, fifo_admin->token_size, wc, rc, tc, sc, nrt-diff-sc, diff-tc);
#ifdef MULTITHREADED
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
}

uint32_t fifo_spaces(fifo_t * const fifo_admin)
{
  if (fifo_admin == NULL) exit(EXIT_FAILURE);
#ifdef MULTITHREADED
  pthread_mutex_lock(&fifo_admin->mut);
#endif
  uint32_t const s = fifo_admin->nr_tokens - ((uint32_t) (fifo_admin->wc - fifo_admin->rc)) - fifo_admin->sc;
#ifdef MULTITHREADED
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
  return s;
}

uint32_t fifo_tokens(fifo_t * const fifo_admin)
{
  if (fifo_admin == NULL) exit(EXIT_FAILURE);
#ifdef MULTITHREADED
  pthread_mutex_lock(&fifo_admin->mut);
#endif
  uint32_t const t = ((uint32_t) (fifo_admin->wc - fifo_admin->rc)) - fifo_admin->tc;
#ifdef MULTITHREADED
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
  return t;
}

void * fifo_claim_space(fifo_t * const fifo_admin)
{
  if (fifo_admin == NULL) exit(EXIT_FAILURE);
#ifdef MULTITHREADED
  pthread_mutex_lock(&fifo_admin->mut);
#endif
  uint64_t const wcc = fifo_admin->wc;
  uint32_t const scc = fifo_admin->sc;
  uint32_t const token_size = fifo_admin->token_size;
  uint32_t const nr_tokens = fifo_admin->nr_tokens;
  uint32_t const diff = nr_tokens - scc;
  while (diff == ((uint32_t) (wcc - fifo_admin->rc))) {
#ifdef MULTITHREADED
    pthread_cond_wait(&fifo_admin->new_space, &fifo_admin->mut);
#endif
  }
  void * const tok = (void *) (((char *) fifo_admin->tokens) + (((uint32_t) ((wcc + scc) % nr_tokens)) * token_size));
  fifo_admin->sc = scc +1;
#ifdef MULTITHREADED
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
  return tok;
}

void fifo_release_token(fifo_t * const fifo_admin)
{
  fifo_release_tokens (fifo_admin, 1);
}

void fifo_release_tokens(fifo_t * const fifo_admin, uint16_t tokens)
{
  if (fifo_admin == NULL) exit(EXIT_FAILURE);
#ifdef MULTITHREADED
  pthread_mutex_lock(&fifo_admin->mut);
#endif
  uint32_t const scc = fifo_admin->sc;
  if (scc < tokens) {
    printf("error: sc=%d < tokens=%d\n", scc, tokens);
    fifo_print_status(fifo_admin);
    exit(EXIT_FAILURE);
  }
  fifo_admin->sc = scc - tokens;
  fifo_admin->wc += tokens;
#ifdef MULTITHREADED
  pthread_cond_signal(&fifo_admin->new_space);
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
}

void * fifo_claim_token(fifo_t * const fifo_admin)
{
  if (fifo_admin == NULL) exit(EXIT_FAILURE);
#ifdef MULTITHREADED
  pthread_mutex_lock(&fifo_admin->mut);
#endif
  uint64_t const rcc = fifo_admin->rc;
  uint32_t const tcc = fifo_admin->tc;
  uint32_t const token_size = fifo_admin->token_size;
  uint32_t const nr_tokens = fifo_admin->nr_tokens;
  while ((uint32_t) (fifo_admin->wc - rcc) == tcc) {
#ifdef MULTITHREADED
    pthread_cond_wait(&fifo_admin->new_token, &fifo_admin->mut);
#endif
  }
  void * const tok = (void *) (((char *) fifo_admin->tokens) + (((uint32_t) ((rcc + tcc) % nr_tokens)) * token_size));
  fifo_admin->tc = tcc +1;
#ifdef MULTITHREADED
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
  return tok;
}

void fifo_release_space(fifo_t * const fifo_admin)
{
  fifo_release_spaces (fifo_admin, 1);
}

void fifo_release_spaces(fifo_t * const fifo_admin, uint16_t spaces)
{
  if (fifo_admin == NULL) exit(EXIT_FAILURE);
#ifdef MULTITHREADED
  pthread_mutex_lock(&fifo_admin->mut);
#endif
  uint32_t const tcc = fifo_admin->tc;
  if (tcc < spaces) {
    printf("error: tc=%d < spaces=%d\n", tcc, spaces);
    fifo_print_status(fifo_admin);
    exit(EXIT_FAILURE);
  }
  fifo_admin->tc = tcc - spaces;
  fifo_admin->rc += spaces;
#ifdef MULTITHREADED
  pthread_cond_signal(&fifo_admin->new_token);
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
}

void fifo_read_token(fifo_t * const fifo_admin, void * const new_token)
{
  if (fifo_admin == NULL || new_token == NULL) exit(EXIT_FAILURE);
#ifdef MULTITHREADED
  pthread_mutex_lock(&fifo_admin->mut);
#endif
  uint32_t const tcc = fifo_admin->tc;
  if (tcc > 0) {
    printf("error: tc=%d > 0 (we don't allow this in fifo_read_token to avoid confusion)\n", tcc);
    fifo_print_status(fifo_admin);
    exit(EXIT_FAILURE);
  }
  uint32_t const rcc = fifo_admin->rc;
  uint32_t const token_size = fifo_admin->token_size;
  uint32_t const nr_tokens = fifo_admin->nr_tokens;
#ifdef MULTITHREADED
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
  do {
#ifdef MULTITHREADED
    pthread_mutex_lock(&fifo_admin->mut);
#endif
    if (fifo_admin->wc != rcc) break;
#ifdef MULTITHREADED
    pthread_mutex_unlock(&fifo_admin->mut);
#endif
  } while (true);
  // slow % calculation
  void * const tok = (void *) (((char *) fifo_admin->tokens) + (((uint32_t) (rcc % nr_tokens)) * token_size));
  for (int i=0; i < token_size; i++) ((char *) new_token)[i] = ((char *) tok)[i];
  fifo_admin->rc = rcc +1;
#ifdef MULTITHREADED
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
}

void fifo_write_token(fifo_t * const fifo_admin, void const * const token_to_write)
{
  if (fifo_admin == NULL || token_to_write == NULL) exit(EXIT_FAILURE);
#ifdef MULTITHREADED
  pthread_mutex_lock(&fifo_admin->mut);
#endif
  uint32_t const scc = fifo_admin->sc;
  if (scc > 0) {
    printf("error: sc=%d > 0 (we don't allow this in fifo_write_token to avoid confusion)\n", scc);
    fifo_print_status(fifo_admin);
    exit(EXIT_FAILURE);
  }
  uint32_t const wcc = fifo_admin->wc;
  uint32_t const token_size = fifo_admin->token_size;
  uint32_t const nr_tokens = fifo_admin->nr_tokens;
#ifdef MULTITHREADED
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
  do {
#ifdef MULTITHREADED
    pthread_mutex_lock(&fifo_admin->mut);
#endif
    if (nr_tokens != wcc - fifo_admin->rc) break;
#ifdef MULTITHREADED
    pthread_mutex_unlock(&fifo_admin->mut);
#endif
  } while (true);
  // slow % calculation
  void * const tok = (void *) (((char *) fifo_admin->tokens) + (((uint32_t) (wcc % nr_tokens)) * token_size));
  for (int i=0; i < token_size; i++) ((char *) tok)[i] = ((char *) token_to_write)[i];
  fifo_admin->wc = wcc +1;
#ifdef MULTITHREADED
  pthread_mutex_unlock(&fifo_admin->mut);
#endif
}
