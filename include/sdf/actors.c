/* Copyright Kees Goossens, Ingo Sander 2023 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void actor_function_template (void * const * const input_tokens, void * const * const output_tokens)
{
  /*
  // read inputs
  // inputs from different channels may have differen types
  // to avoid further indirections, all input tokens are linearised into a single array
  // e.g. channel 0 with 2 tokens, channel 1 with 1 token --> input_tokens = ch0tok0, ch0tok1, ch1tok0
  type const input_ch0_tok0 = * (type *) (input_tokens[0]);
  type const input_ch0_tok1 = * (type *) (input_tokens[1]);
  type const input_ch1_tok0 = * (type *) (input_tokens[2]);
  // similarly for output tokens
  type * const output_ch0_tok0 = (type *) (output_tokens[0]);
  type * const output_ch0_tok1 = (type *) (output_tokens[1]);
  type * const output_ch1_tok0 = (type *) (output_tokens[2]);
  // use inputs to compute outputs, e.g.
  // *output_ch0_tok0 = input_ch0_tok0 +1;
  */
}

void actor0_function (void * const * const input_tokens, void * const * const output_tokens)
{
  uint32_t const input_ch0_tok0 = * (uint32_t *) ((void **) input_tokens)[0];
  uint32_t * const output_ch0_tok0 = (uint32_t *) (output_tokens[0]);
  uint32_t * const output_ch0_tok1 = (uint32_t *) (output_tokens[1]);
  uint32_t * const output_ch1_tok0 = (uint32_t *) (output_tokens[2]);
  *output_ch0_tok0 = input_ch0_tok0+1;
  *output_ch0_tok1 = input_ch0_tok0+2;
  *output_ch1_tok0 = input_ch0_tok0+2; // self edge
  printf("actor0 function: input1=%d output11=%d output12=%d output2=%d\n", input_ch0_tok0, *output_ch0_tok0, *output_ch0_tok1, *output_ch1_tok0);
}

void actor1_function (void * const * const input_tokens, void * const * const output_tokens)
{
  uint32_t const input_ch0_tok0 = * (uint32_t *) (input_tokens[0]);
  double const input_ch1_tok0 = * (double *) (input_tokens[1]);
  char * const output_ch0_tok0 = (char *) (output_tokens[0]);
  (void) snprintf(output_ch0_tok0, 70, "actor 2's input is %d, and this is the output", input_ch0_tok0);
  printf("actor1 function: input1=%d input2=%d output=\"%s\"\n", input_ch0_tok0, (int) input_ch1_tok0, output_ch0_tok0);
}

void actor2_function (void * const * const input_tokens, void * const * const output_tokens)
{
  char const * const input_ch0_tok0 = (char *) (input_tokens[0]);
  int input_int;
  (void) sscanf (input_ch0_tok0, "actor 2's input is %d, and this is the output", &input_int);
  double * const output_ch0_tok0 = (double *) (output_tokens[0]);
  *output_ch0_tok0 = input_int * 1.5;
  printf("actor2 function: input=\"%s\" output=%d\n", input_ch0_tok0, (int) *output_ch0_tok0);
}

