#include<stdlib.h>
#include "utils.h"

void merge(int *arr, int l, int r) {
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

int *sort(int *arr, int len) {
    int *sorted = malloc(len*sizeof(int));
    for (int i = 0; i < len; i++) {
        sorted[i] = arr[i];
    }
    mergesort(sorted, 0, len);
    return sorted;
}
