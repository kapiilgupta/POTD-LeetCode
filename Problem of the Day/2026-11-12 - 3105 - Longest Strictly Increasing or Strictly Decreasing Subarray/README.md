# 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

**Date:** November 12, 2026  
**LeetCode:** [3105. Longest Strictly Increasing or Strictly Decreasing Subarray](https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/)

## Problem Summary

Given an integer array `nums`, find the length of the longest contiguous subarray that is either strictly increasing or strictly decreasing.

A subarray is strictly increasing when every element is greater than the previous one. It is strictly decreasing when every element is smaller than the previous one.

## Approach 1: Single Pass (Optimal)

Maintain three variables:

- `inc`: length of the current strictly increasing subarray.
- `dec`: length of the current strictly decreasing subarray.
- `ans`: maximum length found so far.

Traverse the array from index 1:

1. If `nums[i] > nums[i - 1]`, extend the increasing run by incrementing `inc`; otherwise, reset `inc` to 1.
2. If `nums[i] < nums[i - 1]`, extend the decreasing run by incrementing `dec`; otherwise, reset `dec` to 1.
3. Update the answer with the maximum of `ans`, `inc`, and `dec`.

Equal adjacent elements break both strictly monotonic runs, so both counters reset to 1.

The implementation returns `ans` after the traversal.

## Approach 2: Two Separate Passes (Alternative)

The commented alternative in `solution.cpp` checks increasing and decreasing runs independently:

1. First pass: maintain a current increasing-run length and its maximum.
2. Second pass: maintain a current decreasing-run length and its maximum.
3. Return the maximum of the two results.

This approach is also linear, but it traverses the array twice.

## C++ Solution

See [solution.cpp](./solution.cpp). Both approaches are preserved there: the single-pass implementation is active, and the two-pass implementation is included as a commented alternative.

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
|---|---:|---:|
| Single pass | `O(n)` | `O(1)` |
| Two separate passes | `O(n)` | `O(1)` |

Here, `n` is the number of elements in `nums`.

## Key Takeaway

For contiguous strictly monotonic subarrays, compare each element with its immediate predecessor. Reset the corresponding running length whenever the strict condition breaks. Tracking increasing and decreasing runs together allows the answer to be found in one traversal using constant extra space.
