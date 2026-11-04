# 3505. Minimum Operations to Make Elements Within K Subarrays Equal

- **Date:** 2026-11-04
- **Platform:** [LeetCode](https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/)
- **Difficulty:** Hard
- **Topics:** Array, Sliding Window, Fenwick Tree (Binary Indexed Tree), Dynamic Programming, Coordinate Compression

## Problem

Given an integer array `nums` and integers `x` and `k`, choose exactly `k` non-overlapping subarrays of length `x`. In each chosen subarray, the minimum number of operations needed to make all its elements equal is the sum of absolute differences from a chosen target. Return the minimum total operations.

## Approach: Sliding Window + Fenwick Tree + Dynamic Programming

The solution separates the problem into two parts:

### 1. Calculate the cost of every window of length `x`

For a window, the value that minimizes the sum of absolute differences is its **median**.

- Coordinate-compress the array values so they can be indexed efficiently.
- Maintain a Fenwick Tree for frequencies (`cnt`) and another for value sums (`sm`).
- Slide a window of length `x` by adding the incoming value and removing the outgoing value.
- Use Fenwick Tree binary lifting to find the median order statistic.
- Use the prefix count and prefix sum around the median to calculate the total absolute-difference cost in `O(log n)`.

The resulting `cost[i]` stores the minimum operations required to make the window starting at index `i` equal.

### 2. Choose exactly `k` non-overlapping windows

Use dynamic programming:

- `prev[i]`: minimum cost to choose the required number of windows from the first `i` elements in the previous DP layer.
- `cur[i]`: minimum cost using the current number of windows.

For each position, either:
- Skip the current position: `cur[i - 1]`
- Choose the window ending at `i - 1`: `prev[i - x] + cost[i - x]`

Transition:

`cur[i] = min(cur[i - 1], prev[i - x] + cost[i - x])`

This ensures selected windows do not overlap. Rolling DP arrays keep the memory usage lower.

## C++ Solution

See [`solution.cpp`](solution.cpp).

## Complexity Analysis

Let `n = nums.size()` and `m` be the number of distinct values.

- **Coordinate compression:** `O(n log n)`
- **Window costs:** `O(n log m)` using Fenwick Tree updates and median selection.
- **Dynamic programming:** `O(kn)`
- **Total Time:** `O(n log n + n log m + kn)`
- **Auxiliary Space:** `O(n + m)` for compressed values, ranks, window costs, Fenwick Trees, and rolling DP arrays.

## Key Takeaway

This problem combines two powerful patterns:

1. **Median minimizes absolute deviations** for each fixed-size window.
2. **Dynamic programming with a skip-or-take transition** selects exactly `k` non-overlapping windows.

When a problem asks for an optimal cost over many fixed-size segments, consider precomputing each segment's cost efficiently and then applying DP.

---

*Hard problems are solved by combining patterns. Keep learning, keep experimenting, and keep showing up. 🚀*
