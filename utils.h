#ifndef UTIL_H_
#define UTIL_H_

#include<stdbool.h>

int *sort (int *arr, int len);

struct BSTNode {
    char *key;
    int val;
    struct BSTNode *left;
    struct BSTNode *right;
};

void bst_insert (struct BSTNode **head, char *key, int val);

int bst_find (struct BSTNode *head, char *key);

bool bst_contains (struct BSTNode *head, char *key);

void bst_destroy (struct BSTNode *head);

#endif
