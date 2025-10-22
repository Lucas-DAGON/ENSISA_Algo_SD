#include <math.h>
#include <stdio.h>
#include "..\include\search.h"
#include "..\include\utils.h"

int linear_search(int *arr, int n, int target)
{
    // linear search, return index of target
    // return -1 if not found
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int jump_search(int *arr, int n, int target)
{
    // jump search on sorted array, return index
    // of target, return -1 if not found
    int step = sqrt(n);
    int prev = 0;
    while (arr[min_int(step, n)-1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >=n) return -1;
    }

    for (int i = prev; i < min_int(step, n); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int binary_search(int *arr, int n, int target)
{
    // binary search on sorted array, return index
    // of target, return -1 if not found
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}