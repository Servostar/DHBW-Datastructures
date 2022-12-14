#include "binheap/binheap.h"
#include "hashtable/hashtable.h"
#include "bst/bst.h"
#include "utils/arrays.h"

void testMaxbinheap() {
  // random array of values
  const int array[] = { 1, 2, 3, 4, 5, 6, 7 };
  
  // sorted binary max heap
  Maxbinheap heap = fromArray(array, sizeof(array) / sizeof(int) + 1);

  insert(&heap, 8);
    
  print_array(heap.array, heap.size);

  // free memory
  destroyMaxbinheap(&heap);
}

void testHashmap() {
  Hashmap table = new_hashmap(10);

  put(&table, "Henry", 14);
  put(&table, "Henry", 17);
  put(&table, "Jenifer", 35);
  put(&table, "Harry", 42);

  hashmap_remove(&table, "Jenifer");

  print_hashmap(&table);

  destroy_hashmap(&table);
}

void test_bst() {
  Bst bst = bst_new();

  bst_insert(&bst, 'v');
  bst_insert(&bst, 'b');
  bst_insert(&bst, 'a');
  bst_insert(&bst, 'd');

  bst_remove(&bst, 'v');

  printf("found: %d\n", bst_search(&bst, 'a') );
  printf("max: %c\n", bst_max(&bst));

  bst_destroy(&bst);
}

int main() {
  // testMaxbinheap();

  // testHashmap();

  test_bst();

  return 0;
}
