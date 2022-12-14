
#ifndef _BST_H_
#define _BST_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  char value;
  struct node *left;
  struct node *right;
} Node;

typedef struct bst {
  Node *root;
} Bst;

Bst bst_new();
void bst_destroy(Bst *bst);

void bst_insert(Bst *bst, char value);
void bst_remove(Bst *bst, char value);
bool bst_search(Bst *bst, char value);

char bst_max(Bst *bst);
char bst_min(Bst *bst);

#endif
