# Dynamic Midpoint Binary Search 🚀

## Overview

This repository showcases an enhanced binary search algorithm that adjusts the midpoint based on the target’s relationship to the array boundaries (nums[l] and nums[r]). The goal is to optimize search performance by reducing unnecessary halving of the search space and short-circuiting the search when possible.

## Work in Progress

- **Benchmarking:** Developed comprehensive C benchmarking code (`benchmark_binary_search_large.c`) to compare the performance of the improved algorithm against the standard binary search across large datasets.
- **C Implementation:** Transitioned the improved algorithm from Python to C to leverage compiled language performance benefits.
- **Further Optimizations:** Exploring potential optimizations and alternative algorithms to enhance search efficiency.

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
  - **All Dataset Sizes (100k, 1M, 10M, 50M):** Both **Improved** and **Standard Binary Searches** exhibit **identical or near-identical** performance, indicating no significant advantage in this distribution.

- **High Out-of-Bounds Distribution:**
  - **100k Elements:** The **Improved Binary Search** is **slower** (0.024s vs. 0.010s) than the **Standard Binary Search**.
  - **1M, 10M, 50M Elements:** The **Improved Binary Search** **outperforms** the **Standard Binary Search** (e.g., 0.010s vs. 0.011s at 1M elements), showcasing potential scalability benefits in handling out-of-bound targets.

- **Clustered Near Boundaries Distribution:**
  - **All Dataset Sizes:** The **Improved Binary Search** shows **marginal improvements** or performs **on par** with the **Standard Binary Search**, but the differences are not substantial enough to be considered significant.

**Conclusion:**

While the Improved Binary Search demonstrates marginal performance gains in certain scenarios—particularly with high out-of-bounds targets in larger datasets—the benefits are not substantial enough to justify the added complexity in most cases. The Standard Binary Search remains highly efficient and simpler to implement, making it the preferred choice.

## Next Steps

- **Implement and Benchmark in C:** Continue refining the improved algorithm and explore its performance with larger datasets (e.g., 100 million elements).
- **Optimize the Improved Algorithm:** Reduce conditional branches, explore loop unrolling, and enhance cache locality.
- **Compare with C's `bsearch`:** Ensure fair benchmarking and investigate why `bsearch` underperforms, adjusting the benchmark if necessary.
- **Explore Alternative Implementations:** Consider using other programming languages or leveraging existing optimized libraries for better performance.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests with additional test cases, optimizations, or suggestions to enhance the benchmarks and algorithm implementations.

## Solution Link

- [View LeetCode Submission (C)](https://leetcode.com/problems/binary-search/submissions/1526367344)

- [View LeetCode Submission (Python)](https://leetcode.com/problems/binary-search/submissions/1525837756)
