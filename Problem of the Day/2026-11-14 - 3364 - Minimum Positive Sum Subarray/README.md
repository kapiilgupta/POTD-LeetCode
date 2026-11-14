# 3364. Minimum Positive Sum Subarray

**Date:** November 14, 2026  
**LeetCode:** [3364. Minimum Positive Sum Subarray](https://leetcode.com/problems/minimum-positive-sum-subarray/)

## Problem Summary

Given an integer array `nums` and two integers `l` and `r`, find the minimum positive sum among all contiguous subarrays whose lengths are between `l` and `r`, inclusive.

If no subarray in the allowed length range has a positive sum, return `-1`.

## Approach: Prefix Sum + Brute Force

The solution uses prefix sums to calculate each candidate subarray's sum in constant time, while enumerating all valid starting indices and lengths.

### 1. Build the prefix sum array

Create an array `pre` where:

```text
pre[i] = nums[0] + nums[1] + ... + nums[i]
```

This allows any subarray sum to be calculated without iterating over its elements again.

### 2. Enumerate all valid subarrays

For every starting index `i`, try every permitted length from `l` through `r`, ensuring the subarray stays within the array bounds.

For a subarray starting at `i` with length `len`, its ending index is:

```text
end = i + len - 1
```

Its sum is:

```text
sum = pre[end] - (i > 0 ? pre[i - 1] : 0)
```

### 3. Track the minimum positive sum

If the calculated sum is greater than zero, update the answer with the smaller of the current answer and this sum.

After checking every valid subarray, return the minimum positive sum. If the answer was never updated, return `-1`.

## C++ Solution

See [solution.cpp](./solution.cpp) for the implementation.

The debugging `cout` statement from the submitted draft is omitted so the solution does not produce unwanted output. The inner loop variable is named `len` to distinguish it from the input parameter `l`.

## Complexity Analysis

Let `n` be the length of `nums`.

- **Time Complexity:** `O(n * (r - l + 1))`, bounded by `O(nr)). Prefix sums take `O(n)`, and the nested loops examine every allowed starting-index/length combination. Each sum is evaluated in `O(1)`.
- **Auxiliary Space Complexity:** `O(n)` for the prefix sum array.

## Key Takeaway

Prefix sums turn repeated subarray-sum calculations into constant-time queries. This makes it straightforward to enumerate all subarrays within a given length range and track the smallest positive sum.
