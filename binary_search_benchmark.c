#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Improved Binary Search Function
 */
int improved_binary_search(int* nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize - 1;

    while (l <= r) {
        if (r - l < 2) {
            if (nums[l] == target) return l;
            if (nums[r] == target) return r;
            return -1;
        }

        int mid = l + (r - l) / 2;
        int last_left_value = nums[mid];
        int first_right_value = nums[mid + 1];

        int m;
        if (target < last_left_value) {
            m = l + (mid - l) / 2;
        }
        else if (target > first_right_value) {
            m = mid + 1 + (r - (mid + 1)) / 2;
        }
        else {
            m = mid;
        }

        if (nums[m] == target) {
            return m;
        }
        else if (nums[m] < target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return -1;
}

/**
 * Standard Binary Search Function
 */
int standard_binary_search(int* nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return -1;
}

/**
 * Utility Function to Generate a Random Target
 * Ensures some targets are out of bounds for testing the improved algorithm's benefits
 */
int generate_random_target(int numsSize) {
    int out_of_bound_chance = rand() % 100;
    if (out_of_bound_chance < 20) {  // 20% chance to be out of bounds
        if (rand() % 2) {
            return -1 * (rand() % 1000 + 1);  // Below lower bound
        }
        else {
            return numsSize + rand() % 1000 + 1;  // Above upper bound
        }
    }
    else {
        return rand() % numsSize;  // Within bounds
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Define dataset sizes
    int dataset_sizes[] = {100000, 1000000, 10000000};
    int num_datasets = sizeof(dataset_sizes) / sizeof(dataset_sizes[0]);

    // Define number of iterations
    int iterations = 100000;

    // Iterate over each dataset size
    for (int d = 0; d < num_datasets; d++) {
        int size = dataset_sizes[d];
        // Allocate memory for the array
        int* nums = (int*)malloc(size * sizeof(int));
        if (!nums) {
            printf("Memory allocation failed for size %d\n", size);
            return 1;
        }

        // Initialize the sorted array
        for (int i = 0; i < size; i++) {
            nums[i] = i;
        }

        // Variables to store total time
        clock_t start, end;
        double time_improved = 0.0, time_standard = 0.0;

        // Benchmark Improved Binary Search
        start = clock();
        for (int i = 0; i < iterations; i++) {
            int target = generate_random_target(size);
            int res = improved_binary_search(nums, size, target);
            // Optionally verify the result here
        }
        end = clock();
        time_improved = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Benchmark Standard Binary Search
        start = clock();
        for (int i = 0; i < iterations; i++) {
            int target = generate_random_target(size);
            int res = standard_binary_search(nums, size, target);
            // Optionally verify the result here
        }
        end = clock();
        time_standard = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Display Results
        printf("Dataset Size: %d elements\n", size);
        printf("Iterations: %d\n", iterations);
        printf("Improved Binary Search Time: %.5f seconds\n", time_improved);
        printf("Standard Binary Search Time: %.5f seconds\n\n", time_standard);

        // Free allocated memory
        free(nums);
    }

    return 0;
}
