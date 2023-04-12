#ifndef UTIL_H_
#define UTIL_H_

int *sort (int *arr, int len);

struct BSTNode;

void bst_insert (struct BSTNode **head, char *key, int val);

int bst_find (struct BSTNode *head, char *key);

int bst_contains (struct BSTNode *head, char *key);

void bst_destroy (struct BSTNode *head);

#endif
