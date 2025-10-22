#include <stdlib.h>
#include "..\include\sort.h"
#include "..\include\utils.h"

void selection_sort(int *arr, int n)
{
    // selection sort iterative
    for (int i = 0; i < n - 2; i++){
        int min = i;
        for (int j = i + 1; j < n - 1; j++){
            if (arr[j] < arr[min]) min = j;
        }
        swap_int(&arr[i], &arr[min]);
    }
}

void insertion_sort(int *arr, int n)
{
    // insertion sort iterative
    for (int i = 1; i < n - 1; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

void bubble_sort(int *arr, int n)
{
    // bubble sort iterative
    for (int i = 0; i < n - 2; i++){
        for (int j = 0; j < n - 2 - i; j++){
            if (arr[j] > arr[j + 1]) swap_int(&arr[j], &arr[j + 1]);
        }
    }
}

void merge(int *arr, int *tmp, int l, int m, int r)
{
    // merge function
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r){
        if (arr[i] <=  arr[j]){
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
}

void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    // recursive steps of merge sort
    if (l < r){
        int mil = l + (r - l) / 2;
        mergesort_rec(arr, tmp, l, mil);
        mergesort_rec(arr, tmp, mil + 1, r);
        merge(arr, tmp, l, mil, r);
        for (int i = l; i <= r; i++){
            arr[i] = tmp[i];
        }
    }
}

void merge_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}

int partition(int *arr, int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++){
        if (arr[j] <= pivot){
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quick_sort_rec(int *arr, int l, int r)
{
    // recursive steps of quick sort
    if (l < r){
        int p = partition(arr, l, r);
        quick_sort_rec(arr, l, p - 1);
        quick_sort_rec(arr, p + 1, r);
    }
}

void quick_sort(int *arr, int n)
{
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}