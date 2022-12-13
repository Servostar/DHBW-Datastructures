#include "binheap/binheap.h"
#include "utils/arrays.h"

int main() {
  Maxbinheap heap = newMaxbinheap(40);

  insert(&heap, 1);
  insert(&heap, 3);
  insert(&heap, 8);
  insert(&heap, 4);

  print_array(heap.array, heap.size);

  destroyMaxbinheap(&heap);
  return 0;
}
