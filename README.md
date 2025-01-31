# Dynamic Midpoint Binary Search 🚀

## Overview

This repo presents an approach to binary search that can short-circuit certain comparisons by dynamically adjusting the midpoint based on the target’s relationship to the boundaries (`nums[l]` and `nums[r]`).

## Work in Progress

I will be improving the code and adding more **benchmarking data** to demonstrate the performance and correctness of this solution.

## How It Works

1. **Check boundary conditions**:
   - If `target < nums[l]`, set `m = l`.
   - If `target > nums[r]`, set `m = r`.
   - Otherwise, use the standard midpoint `(l + r) // 2`.
2. **Compare and move the boundaries** until `l > r`.

By short-circuiting cases where the target is clearly out of bounds, we can reduce the search space more quickly in certain scenarios.

## Complexity Analysis

- **Time Complexity**: \(O(\log n)\) in the worst case, similar to standard binary search.
- **Space Complexity**: \(O(1)\), since we perform in-place checks without extra data structures.

## Performance

Work in progress.

## Contributing

Feel free to open issues or submit PRs with additional test cases.

## Solution Link

[View LeetCode Submission version 2](https://leetcode.com/problems/binary-search/submissions/1525837756)

[View LeetCode Submission version 1](https://leetcode.com/submissions/detail/1524739686/)
