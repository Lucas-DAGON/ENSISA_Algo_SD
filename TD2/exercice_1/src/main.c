#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\include\search.h"
#include "..\include\utils.h"

# define ARRAY_SIZE 100000000
# define MAX_VALUE 100000000

int main(void)
{
    int* arr = malloc(ARRAY_SIZE * sizeof(int));
    clock_t start, end;
    float cpu_runtime;

    // random array example
    srand(time(NULL));
    // Generate random numbers between 1 and 1000
    start = clock();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % MAX_VALUE + 1;  // 1 to 1000
    }
    end = clock();
    cpu_runtime = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken (rand): %f seconds\n", cpu_runtime);
    

    /*// Sorted array example
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i;
    }*/

    // Define target
    srand(time(NULL));
    int target = rand() % MAX_VALUE; //rand() % ARRAY_SIZE;
    printf("Target: %d\n", target);
    

    if (is_sorted_nondecreasing(arr, sizeof(arr)/sizeof(arr[0]))) {
        start = clock();
        printf("Linear Search Index: %d\n", linear_search(arr, ARRAY_SIZE, target));
        end = clock();
        cpu_runtime = ((float)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken (linear search): %f seconds\n", cpu_runtime);
        free(arr);
    }
    else {
        printf("Array is sorted, proceeding with jump and binary search.\n");

        start = clock();
        printf("Jump Search Index: %d\n", jump_search(arr, ARRAY_SIZE, target));
        end = clock();
        cpu_runtime = ((float)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken (jump search): %f seconds\n", cpu_runtime);

        start = clock();
        printf("Binary Search Index: %d\n", binary_search(arr, ARRAY_SIZE, target));
        end = clock();
        cpu_runtime = ((float)(end - start)) / CLOCKS_PER_SEC;
        printf("Time taken (binary search): %f seconds\n", cpu_runtime);

        free(arr);
    }
    

    
    return 0;
}
