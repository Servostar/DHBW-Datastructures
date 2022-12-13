
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
// create a new binary heap from the array
Maxbinheap fromArray(const int* array, unsigned int len);

// add new element
void insert(Maxbinheap *heap, int element);

// remove maximum element
int removeMax(Maxbinheap *heap);

// sort array using an inplace binary heap
void heapsort(int* array, const int len);

#endif
