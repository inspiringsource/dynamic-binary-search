#include <stdio.h>
#include <stdlib.h>

/**
 * As was submitted on leetcode.com
 * Note: The `nums` array is assumed to be sorted in ascending order.
 * The function returns the index of `target` if found; otherwise, it returns -1.
 */

int search(int* nums, int numsSize, int target) {
    int l = 0;
    int r = numsSize - 1;

    while (l <= r) {
        // If the search window has 1 or 2 elements, perform direct checks
        if (r - l < 2) {
            if (nums[l] == target) {
                return l;
            }
            if (nums[r] == target) {
                return r;
            }
            return -1;  // Target not found in the small window
        }

        // Calculate the standard midpoint
        int mid = l + (r - l) / 2;

        // Retrieve values at mid and mid + 1
        int last_left_value = nums[mid];
        int first_right_value = nums[mid + 1];

        int m;  // Dynamic midpoint

        // Dynamic midpoint adjustment based on target's relation to mid values
        if (target < last_left_value) {
            // Target is in the left half; adjust midpoint towards the left
            m = l + (mid - l) / 2;
        }
        else if (target > first_right_value) {
            // Target is in the right half; adjust midpoint towards the right
            m = mid + 1 + (r - (mid + 1)) / 2;
        }
        else {
            // Target is between last_left_value and first_right_value; use standard midpoint
            m = mid;
        }

        // Check if the dynamic midpoint has the target
        if (nums[m] == target) {
            return m;
        }
        else if (nums[m] < target) {
            // Target is in the right half
            l = m + 1;
        }
        else {
            // Target is in the left half
            r = m - 1;
        }
    }

    // Target not found
    return -1;
}