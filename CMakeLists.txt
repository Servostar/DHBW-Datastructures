cmake_minimum_required(VERSION 3.10)
project(Search)
add_executable(
  Main
  
  src/main.c

  src/bst/bst.h
  src/bst/bst.c

  src/hashtable/hashtable.c
  src/hashtable/hashtable.h

  src/binheap/binheap.c
  src/binheap/binheap.h

  src/utils/arrays.c
  src/utils/arrays.h
)
