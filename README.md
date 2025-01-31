# Dynamic Midpoint Binary Search 🚀

## Overview

This repository showcases an enhanced binary search algorithm that dynamically adjusts the search midpoint based on the target’s relationship to the array boundaries (`nums[l]` and `nums[r]`). The goal is to optimize search performance by reducing unnecessary comparisons.

## Work in Progress

- **Benchmarking**: Developed comprehensive C benchmarking code (`benchmark_binary_search_large.c`) to compare the performance of the improved algorithm against the standard binary search and C's built-in `bsearch` across large datasets.
- **C Implementation**: Transitioned the improved algorithm from Python to C to leverage compiled language performance benefits.
- **Further Optimizations**: Exploring potential optimizations and alternative algorithms to enhance search efficiency.

## How It Works

1. **Check Boundary Conditions**:
   - If `target < nums[l]`, set `m = l`.
   - If `target > nums[r]`, set `m = r`.
   - Otherwise, use the standard midpoint `(l + r) / 2`.
2. **Compare and Adjust**:
   - Short-circuit searches by dynamically adjusting the midpoint based on the target’s position relative to `nums[m]`.
   - Continue adjusting until the target is found or the search space is exhausted.

## Complexity Analysis

- **Time Complexity**: \(O(\log n)\) in the worst case, similar to standard binary search.
- **Space Complexity**: \(O(1)\), utilizing in-place checks without additional data structures.

## Benchmark Results

### **Benchmark Setup**

- **Datasets**:
  - 100,000 elements
  - 1,000,000 elements
  - 10,000,000 elements
- **Iterations**: 100,000 searches per scenario
- **Target Distributions**:
  - **Uniform Random**: Evenly distributed targets across the entire range.
  - **Mostly Out of Bounds**: 20% of targets are outside the array bounds.
  - **Near Boundaries**: Targets clustered near the start or end of the array.

### **Results Summary**

| Dataset Size | Iterations | Improved Binary Search Time (s) | Standard Binary Search Time (s) | C's `bsearch` Time (s) |
|--------------|------------|---------------------------------|---------------------------------|------------------------|
| 100k         | 100k       | 0.01200                          | 0.01100                          | 0.02000                |
| 1M           | 100k       | 0.01100                          | 0.01100                          | 0.03000                |
| 10M          | 100k       | 0.01300                          | 0.01400                          | 0.30000                |

### **Analysis**

- **Standard Binary Search** outperforms the **Improved Binary Search** at lower dataset sizes (100k and 1M elements), showcasing its efficiency and minimalistic design.
- At **10,000,000** elements, the **Improved Binary Search** slightly outperforms the **Standard Binary Search**, indicating potential scalability benefits.
- **C's `bsearch`** consistently underperforms compared to both custom implementations, likely due to the way it's being benchmarked or specific implementation details.

**Note:** Results can vary based on system hardware, compiler optimizations, and specific target distributions. Further testing with larger datasets and varied target distributions is recommended to draw more definitive conclusions.

## Next Steps

- **Implement and Benchmark in C**: Continue refining the improved algorithm and explore its performance with larger datasets (e.g., 100 million elements).
- **Optimize the Improved Algorithm**: Reduce conditional branches, explore loop unrolling, and enhance cache locality.
- **Compare with C's `bsearch`**: Ensure fair benchmarking and investigate why `bsearch` underperforms, adjusting the benchmark if necessary.
- **Explore Alternative Implementations**: Consider using other programming languages or leveraging existing optimized libraries for better performance.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests with additional test cases, optimizations, or suggestions to enhance the benchmarks and algorithm implementations.

## Solution Link

[View LeetCode Submission (c)](https://leetcode.com/problems/binary-search/submissions/1526367344)

[View LeetCode Submission (Python)](https://leetcode.com/problems/binary-search/submissions/1525837756)
