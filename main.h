#ifndef __MAIN_H__
#define __MAIN_H__
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>


typedef struct uint128_t {
	uint64_t x;
	uint64_t y;
} uint128_t;

uint64_t count_shr(uint64_t *n);
uint128_t *uint64_mul(uint64_t *a,uint64_t *b);


#endif
