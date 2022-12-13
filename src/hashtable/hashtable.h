#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Hashtable for strings
 * */
typedef struct hashmap {
  // total amount of buckets
  unsigned int capacity;
  // key data
  const char **keys;
  // value data
  int *values;
} Hashmap;

void put(Hashmap *hashmap, const char* string, const int value);

void hashmap_remove(Hashmap *hashmap, const char* string);

int get(Hashmap *hashmap, const char* string);

Hashmap new_hashmap(unsigned int capacity);

void destroy_hashmap(Hashmap *hashmap);

void print_hashmap(Hashmap *hashmap);

#endif
