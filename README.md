# Dynamic Midpoint Binary Search 🚀

## Overview
This repository presents an optimized binary search algorithm (almost 100% improvement) that dynamically adjusts the midpoint calculation based on the leftmost and rightmost values, rather than always rounding down. This approach can improve search efficiency in some cases.

## Problem Statement
Binary search is an efficient algorithm to find an element in a sorted array. The standard implementation always computes the midpoint using:

```python
m = (l + r) // 2
```

## Optimization Idea
Instead of always computing `m` the same way, our **Dynamic Midpoint Strategy** adjusts it based on the values at the left (`nums[l]`) and right (`nums[r]`) boundaries to improve efficiency.

## Performance Improvement
- **Standard Binary Search:** `238 ms`
- **Optimized Dynamic Midpoint Search:** `3 ms`
- **Improvement:**  **98.74% faster** on Leetcode

## Solution Link
[View LeetCode Submission](https://leetcode.com/submissions/detail/1524739686/)

