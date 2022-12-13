#include "binheap.h"

Maxbinheap newMaxbinheap(unsigned int capacity) {
  Maxbinheap heap = {
    .capacity = capacity,
    .size = 0,
    .array = (int*) calloc(capacity, sizeof(int))
  };

  return heap;
}

void destroyMaxbinheap(Maxbinheap *heap) {
  free(heap->array);
  heap->capacity = 0;
  heap->array = NULL;
  heap->size = 0;
}

void swim(Maxbinheap *heap, int k) {
  while (k > 1 && heap->array[k / 2] < heap->array[k]) {
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
  if (heap->size + 1 == heap->capacity)
    return;

  heap->array[heap->size] = element;
  heap->size ++;

  swim(heap, heap->size);
}
