#include "binheap.h"
#include <stdlib.h>

Maxbinheap newMaxbinheap(unsigned int capacity) {
  Maxbinheap heap = {
    .capacity = capacity,
    .size = 0,
    .array = (int*) calloc(capacity, sizeof(int))
  };

  return heap;
}

void destroyMaxbinheap(Maxbinheap *heap) {
  // deallocate memory
  free(heap->array);
  // clear data
  heap->capacity = 0;
  heap->array = NULL;
  heap->size = 0;
}

Maxbinheap fromArray(const int* array, unsigned int len) {
  Maxbinheap heap = newMaxbinheap(len);

  for (const int* x = array; x < array + len; x++)
    insert(&heap, *x);

  return heap;
}

void swim(Maxbinheap *heap, int k) {
  while (k > 0) {

    if (heap->array[k / 2] > heap->array[k]) {
      // parent element is larger, we stop
      break;
    }

    // parent is smaller, move the parent down
    swap(heap->array + k, heap->array + k / 2);

    k = k/2;
  }
}

void sink(Maxbinheap *heap, int k) {
  while (2 * k <= heap->size) {
    int j = 2 * k;
    
    // either select left or right child
    if (j < heap->size && heap->array[j] < heap->array[j + 1])
      j ++;
    
    // continue as long as its not high up enough
    if (!(heap->array[k] < heap->array[j]))
      break;

    swap(heap->array + k, heap->array + j);
    k = j;
  }
}

void insert(Maxbinheap *heap, int element) {
  if (heap->size + 1 >= heap->capacity)
    // reallocate the array
    heap->array = reallocarray(heap->array, heap->capacity + 4, sizeof(int));
  
  // insert new element at the end
  heap->array[heap->size] = element;
  heap->size ++;
  
  // let it swim up to its right position
  swim(heap, heap->size - 1);
}

int removeMax(Maxbinheap *heap) {
  int max = heap->array[0];

  heap->size --;
  
  // take smallest element and put in as root
  swap(heap->array, heap->array + heap->size);
  
  // let new root sink in
  sink(heap, 0);

  return max;
}

void sinkArray(int* array, int k, const int len) {
  while (2 * k <= len) {
    int j = 2 * k;
    
    // either select left or right child
    if (j < len && array[j] < array[j + 1])
      j ++;
    
    // continue as long as its not high up enough
    if (!(array[k] < array[j]))
      break;

    swap(array + k, array + j);
    k = j;
  }
}

void heapsort(int* array, const int len) {
  for (int x = len/2; x >= 0; x--)
    sinkArray(array, x, len);

  int n = len;

  while (n > 0) {
    swap(array, array + n);
    n --;
    sinkArray(array, 1, n);
  }
}
