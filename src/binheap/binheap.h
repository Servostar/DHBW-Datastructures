
#ifndef _BINHEAP_H_
#define _BINHEAP_H_

#include <stdlib.h>
#include "../utils/arrays.h"

/**
 * Maximum binary heap for signed integers
*/
typedef struct maxbinheap {
  // amount of elements that fit into the heap
  unsigned int capacity;
  // number of inserted elements
  unsigned int size;
  // data of heap
  int* array;
} Maxbinheap;

// create new heap
Maxbinheap newMaxbinheap(unsigned int capacity);
// free memory
void destroyMaxbinheap(Maxbinheap *heap);

void swim(Maxbinheap *heap, int k);

void sink(Maxbinheap *heap, int k);

void insert(Maxbinheap *heap, int element);

#endif
