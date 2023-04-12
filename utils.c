#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"

void merge (int *arr, int l, int r) {
    int tmp_arr[r - l];
    int mid = (r + l)/2;
    int l_ind = l;
    int r_ind = mid;
    for (int i = l; i < r; i++) {
        if (l_ind >= mid) {
            tmp_arr[i - l] = arr[r_ind];
            r_ind++;
        } else if (r_ind >= r) {
            tmp_arr[i - l] = arr[l_ind];
            l_ind++;
        } else {
            if (arr[l_ind] <= arr[r_ind]) {
                tmp_arr[i - l] = arr[l_ind];
                l_ind++;
            } else {
                tmp_arr[i - l] = arr[r_ind];
                r_ind++;
            }
        }
    }

    for (int i = l; i < r; i++) {
        arr[i] = tmp_arr[i - l];
    }
}

void mergesort (int *arr, int l, int r) {
    if ((r - l) <= 1) return;
    int mid = (r + l)/2;
    mergesort(arr, l, mid);
    mergesort(arr, mid, r);
    merge(arr, l, r);
}

int *sort (int *arr, int len) {
    int *sorted = malloc(len*sizeof(int));
    for (int i = 0; i < len; i++) {
        sorted[i] = arr[i];
    }
    mergesort(sorted, 0, len);
    return sorted;
}

struct BSTNode {
    char *key;
    int val;
    struct BSTNode *left;
    struct BSTNode *right;
};

struct BSTNode *new_bst_node (char *key, int val) {
    struct BSTNode *node = malloc(sizeof(struct BSTNode));
    node->key = key;
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void bst_insert (struct BSTNode **head, char *key, int val) {
    if (*head == NULL) {
        *head = new_bst_node(key, val);
    } else {
        int cmp = strcmp(key, (*head)->key);
        if (cmp == 0) {
            (*head)->val = val;
        } else if (cmp < 0) {
            bst_insert(&((*head)->left), key, val);
        } else {
            bst_insert(&((*head)->right), key, val);
        }
    }
}

int bst_find (struct BSTNode *head, char *key) {
    int cmp = strcmp(key, head->key);
    if (cmp == 0) {
        return head->val;
    } else if (cmp < 0) {
        return bst_find(head->left, key);
    } else {
        return bst_find(head->right, key);
    }
}

int bst_contains (struct BSTNode *head, char *key) {
    if (head == NULL) return 0;

    int cmp = strcmp(key, head->key);
    if (cmp == 0) {
        return 1;
    } else if (cmp < 0) {
        return bst_find(head->left, key);
    } else {
        return bst_find(head->right, key);
    }
}

void bst_destroy(struct BSTNode *head) {
    if (head == NULL) return;
    bst_destroy(head->left);
    bst_destroy(head->right);
    free(head);
}
