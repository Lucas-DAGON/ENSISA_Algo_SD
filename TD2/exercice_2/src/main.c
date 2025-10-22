#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\include\sort.h"
#include "..\include\utils.h"

#define ARRAY_SIZE 10000

int* fill_array_random(int *arr, int n)
{
    // fill array with random integers
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 10000; // random integers between 0 and 9999
    }
    return arr;
}

int main(void)
{
    // Create array example using malloc
    int *arr = (int *)malloc (ARRAY_SIZE * sizeof(int));

    clock_t start, end;
    float cpu_runtime;

    // Fill the array with random integers
    fill_array_random(arr, ARRAY_SIZE);

    // Measure time for bubble sort
    start = clock();
    bubble_sort(arr, ARRAY_SIZE);
    end = clock();
    cpu_runtime = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %f seconds\n", cpu_runtime);

    // Measure time for selection sort
    fill_array_random(arr, ARRAY_SIZE); // Refill array with random integers
    start = clock();
    selection_sort(arr, ARRAY_SIZE);
    end = clock();
    cpu_runtime = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort Time: %f seconds\n", cpu_runtime);

    // Measure time for insertion sort
    fill_array_random(arr, ARRAY_SIZE); // Refill array with random integers
    start = clock();
    insertion_sort(arr, ARRAY_SIZE);
    end = clock();
    cpu_runtime = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort Time: %f seconds\n", cpu_runtime);

    // Measure time for mergesort
    fill_array_random(arr, ARRAY_SIZE); // Refill array with random integers
    start = clock();
    merge_sort(arr, ARRAY_SIZE);
    end = clock();
    cpu_runtime = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort Time: %f seconds\n", cpu_runtime);

    // measure time for quicksort
    fill_array_random(arr, ARRAY_SIZE); // Refill array with random integers
    start = clock();
    quick_sort(arr, ARRAY_SIZE - 1);
    end = clock();
    cpu_runtime = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort Time: %f seconds\n", cpu_runtime);

    // Free allocated memory
    free(arr);
    

    return 0;
}
