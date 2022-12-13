#ifndef _ARRAYS_H_
#define _ARRAYS_H_

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void populate(int *, int);

void shuffle(int *, int);

void gen_worst(int *, int);

void swap(int *, int *);

bool is_sorted(int *, int);

void print_array(int *, int);

void init(int *, int, const char *);

#endif
