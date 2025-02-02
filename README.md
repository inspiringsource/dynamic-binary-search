# Dynamic Midpoint Binary Search 🚀

## Overview

This repository showcases an enhanced binary search algorithm that adjusts the midpoint based on the target’s relationship to the array boundaries (`nums[l]` and `nums[r]`). The goal is to optimize search performance by reducing unnecessary halving of the search space and short-circuiting the search when possible. So far, the algorithm has been implemented in Python and C, with benchmarking code to compare its performance against the standard binary search algorithm. Notably, the improved algorithm beats 100% of other solutions on LeetCode—likely due to the small, specific datasets and unique distributions used for benchmarking there. However, our benchmarks on larger datasets show only marginal performance gains (around a single-digit percentage, roughly 5% at best) in specific scenarios. In most cases, the added complexity does not justify replacing the standard binary search.

## How It Works

1. **Check Boundary Conditions:**
   - If `target < nums[l]`, set `m = l`.
   - If `target > nums[r]`, set `m = r`.
   - Otherwise, use the standard midpoint `(l + r) / 2`.
2. **Compare and Adjust:**
   - Short-circuit searches by dynamically adjusting the midpoint based on the target’s position relative to `nums[m]`.
   - Continue adjusting until the target is found or the search space is exhausted.

## Complexity Analysis

- **Time Complexity:** \(O(\log n)\) in the worst case, similar to standard binary search.
- **Space Complexity:** \(O(1)\), utilizing in-place checks without additional data structures.

## Benchmark Results

### **Benchmark Setup**

- **Datasets:**
  - 100,000 elements
  - 1,000,000 elements
  - 10,000,000 elements
  - 50,000,000 elements
- **Iterations:** 100,000 searches per scenario
- **Target Distributions:**
  - **Uniform Random:** Evenly distributed targets across the entire range.
  - **High Out-of-Bounds:** 20% of targets are outside the array bounds.
  - **Clustered Near Boundaries:** Targets clustered near the start or end of the array.

### **Results Summary**

| Dataset Size | Target Distribution       | Improved Binary Search Time (s) | Standard Binary Search Time (s) |
|--------------|---------------------------|---------------------------------|---------------------------------|
| 100k         | Uniform Random            | 0.01100                         | 0.01100                         |
| 100k         | High Out-of-Bounds        | 0.02400                         | 0.01000                         |
| 100k         | Clustered Near Boundaries | 0.01300                         | 0.01400                         |
| 1M           | Uniform Random            | 0.01200                         | 0.01200                         |
| 1M           | High Out-of-Bounds        | 0.01000                         | 0.01100                         |
| 1M           | Clustered Near Boundaries | 0.01400                         | 0.01300                         |
| 10M          | Uniform Random            | 0.01200                         | 0.01300                         |
| 10M          | High Out-of-Bounds        | 0.01000                         | 0.01200                         |
| 10M          | Clustered Near Boundaries | 0.01400                         | 0.01500                         |
| 50M          | Uniform Random            | 0.01300                         | 0.01300                         |
| 50M          | High Out-of-Bounds        | 0.01100                         | 0.01200                         |
| 50M          | Clustered Near Boundaries | 0.01400                         | 0.01400                         |

### **Analysis**

- **Uniform Random Distribution:**
  - Across all dataset sizes (100k, 1M, 10M, 50M), both the improved and standard binary searches exhibit nearly identical performance.
  
- **High Out-of-Bounds Distribution:**
  - For 100k elements, the improved algorithm is slower (0.024s vs. 0.010s).
  - For larger datasets (1M, 10M, 50M), the improved algorithm marginally outperforms the standard binary search (e.g., 0.010s vs. 0.011s at 1M elements).
  
- **Clustered Near Boundaries Distribution:**
  - Performance differences between the two methods are minimal and not significant enough to justify the added complexity.

**Conclusion:**

The **Improved Binary Search** demonstrates marginal performance gains (up to 5% in certain scenarios with high out-of-bounds targets on large datasets), these improvements are not substantial enough to justify its added complexity in most practical cases.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests with additional test cases, optimizations, or suggestions to enhance the benchmarks and algorithm implementations.

## Solution Link

- [View LeetCode Submission (C)](https://leetcode.com/problems/binary-search/submissions/1526367344)
- [View LeetCode Submission (Python)](https://leetcode.com/problems/binary-search/submissions/1525837756)
