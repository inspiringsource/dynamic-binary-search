#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum dataset size you want to test
#define MAX_DATASET_SIZE 100000000  // 100 million

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
 * Utility Function to Generate a Random Target Based on Distribution
 */
int generate_random_target(int numsSize, int distribution_type) {
    // distribution_type:
    // 0 - Uniform Random
    // 1 - High Out-of-Bounds (50% out-of-bounds)
    // 2 - Clustered Near Boundaries (40% near boundaries)

    int rand_percent = rand() % 100;

    switch(distribution_type) {
        case 1:  // High Out-of-Bounds
            if (rand_percent < 50) {  // 50% out-of-bounds
                if (rand() % 2) {
                    return -1 * (rand() % 1000 + 1);  // Below lower bound
                }
                else {
                    return numsSize + rand() % 1000 + 1;  // Above upper bound
                }
            }
            else {  // 50% within bounds
                return rand() % numsSize;
            }
            break;
        case 2:  // Clustered Near Boundaries
            if (rand_percent < 40) {  // 40% near boundaries
                int edge_zone = numsSize / 20;  // 5% of the list size
                if (rand() % 2) {
                    return rand() % edge_zone;  // Close to min
                }
                else {
                    return numsSize - 1 - (rand() % edge_zone);  // Close to max
                }
            }
            else {  // 60% within bounds
                return rand() % numsSize;
            }
            break;
        default:  // Uniform Random
            return rand() % numsSize;
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Define dataset sizes
    int dataset_sizes[] = {100000, 1000000, 10000000, 50000000};  // Added 50 million
    int num_datasets = sizeof(dataset_sizes) / sizeof(dataset_sizes[0]);

    // Define number of iterations
    int iterations = 100000;

    // Define target distribution types
    // 0 - Uniform Random
    // 1 - High Out-of-Bounds
    // 2 - Clustered Near Boundaries
    int distribution_types[] = {0, 1, 2};
    int num_distributions = sizeof(distribution_types) / sizeof(distribution_types[0]);

    // Iterate over each dataset size
    for (int d = 0; d < num_datasets; d++) {
        int size = dataset_sizes[d];
        if (size > MAX_DATASET_SIZE) {
            printf("Skipping dataset size %d due to MAX_DATASET_SIZE limit.\n", size);
            continue;
        }

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

        // Iterate over each distribution type
        for (int dist = 0; dist < num_distributions; dist++) {
            int distribution_type = distribution_types[dist];
            char* distribution_name;
            switch(distribution_type) {
                case 0:
                    distribution_name = "Uniform Random";
                    break;
                case 1:
                    distribution_name = "High Out-of-Bounds";
                    break;
                case 2:
                    distribution_name = "Clustered Near Boundaries";
                    break;
                default:
                    distribution_name = "Unknown";
            }

            // Declare volatile dummy variables to accumulate results
            volatile int dummy_improved = 0;
            volatile int dummy_standard = 0;

            // Variables to store total time
            clock_t start, end;
            double time_improved = 0.0, time_standard = 0.0;

            // Benchmark Improved Binary Search
            start = clock();
            for (int i = 0; i < iterations; i++) {
                int target = generate_random_target(size, distribution_type);
                int res = improved_binary_search(nums, size, target);
                dummy_improved += res;  // Accumulate results
            }
            end = clock();
            time_improved = ((double)(end - start)) / CLOCKS_PER_SEC;

            // Benchmark Standard Binary Search
            start = clock();
            for (int i = 0; i < iterations; i++) {
                int target = generate_random_target(size, distribution_type);
                int res = standard_binary_search(nums, size, target);
                dummy_standard += res;  // Accumulate results
            }
            end = clock();
            time_standard = ((double)(end - start)) / CLOCKS_PER_SEC;

            // Display Results
            printf("Dataset Size: %d elements\n", size);
            printf("Iterations: %d\n", iterations);
            printf("Target Distribution: %s\n", distribution_name);
            printf("Improved Binary Search Time: %.5f seconds\n", time_improved);
            printf("Standard Binary Search Time: %.5f seconds\n\n", time_standard);
        }

        // Free allocated memory
        free(nums);
    }

    return 0;
}
