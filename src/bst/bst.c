#include "bst.h"
#include <stdlib.h>

Bst bst_new() {
  Bst bst = {
    .root = NULL
  };

  return bst;
}

void dealloc_node(Node *node) {
  if (node == NULL)
    return;

  dealloc_node(node->left);
  dealloc_node(node->right);

  free(node);
}

void bst_destroy(Bst *bst) {
  dealloc_node(bst->root);
}

Node* new_node(char value) {
  Node *n = (Node*) calloc(sizeof(Node), 1);
  n->value = value;
  return n;
}

void place_node(Node *node, char value) {
  if (value > node->value) {

    if (node->right == NULL) {
      node->right = new_node(value);
      return;
    }

    place_node(node->right, value);
  } else {

    if (node->left == NULL) {
      node->left = new_node(value);
      return;
    }

    place_node(node->left, value);
  }
}

void bst_insert(Bst *bst, char value) {
  if (bst->root == NULL) {
    bst->root = new_node(value);
    return;
  }

  place_node(bst->root, value);
}

bool search_node(Node* node, char value) {
  if (value == node->value) {
    return true;
  }

  if (value > node->value) {
    if (node->right == NULL)
      return false;

    return search_node(node->right, value);
  } else {
    if (node->left == NULL)
      return false;

    return search_node(node->left, value);
  }
}

bool bst_search(Bst *bst, char value) {
  return search_node(bst->root, value);
}

Node** minimum(Node *node) {
  if (node->left->left == NULL) {
    return &node->left;
  }

  return minimum(node->left);
}

void remove_node(Node **node, char value) {

  if (value > (*node)->value)
    remove_node(&(*node)->right, value);
  else if (value < (*node)->value)
    remove_node(&(*node)->left, value);
  else {
    if ((*node)->right == (*node)->left) {
      *node = NULL;
    } else if ((*node)->left == NULL) {
      *node = (*node)->right;
    } else if ((*node)->right == NULL) {
      *node = (*node)->left;
    } else {
      Node **min = minimum(*node);
      (*node)->value = (*min)->value;
      *min = NULL;
    }
  }
}

void bst_remove(Bst *bst, char value) {
  if (bst->root == NULL)
    return;

  remove_node(&bst->root, value);
}

char node_max(Node *node) {
  if (node->right == NULL)
    return node->value;
  
  return node_max(node->right);
}

char bst_max(Bst *bst) {
  if (bst->root == NULL)
    return '\0';

  return node_max(bst->root);
}

char node_min(Node *node) {
  if (node->left == NULL)
    return node->value;
  
  return node_min(node->left);
}

char bst_min(Bst *bst) {
  if (bst->root == NULL)
    return '\0';

  return node_min(bst->root);
}


