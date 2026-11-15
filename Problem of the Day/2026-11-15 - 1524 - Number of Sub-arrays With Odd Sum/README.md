# 1524. Number of Sub-arrays With Odd Sum

**Date:** November 15, 2026  
**LeetCode:** [1524. Number of Sub-arrays With Odd Sum](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/)

## Problem Summary

Given an array of integers `arr`, count the number of non-empty contiguous subarrays whose sum is odd. Since the answer can be large, return it modulo `10^9 + 7`.

## Approach 1: Brute Force

The brute-force approach checks every possible subarray.

### Algorithm

1. Iterate over every starting index `i`.
2. Initialize a running sum to zero.
3. Extend the subarray by moving the ending index `j` from `i` to the end of the array.
4. Add `nums[j]` to the running sum.
5. Whenever the sum is odd, increment the answer.
6. Apply the modulo operation and return the final count.

Because the running sum is updated as the ending index moves, each subarray sum is calculated in constant time rather than recomputed from scratch.

### Complexity Analysis

- **Time Complexity:** `O(n^2)` — there are `O(n^2)` possible subarrays, and each is checked in constant time after updating the running sum.
- **Auxiliary Space Complexity:** `O(1)` — only a few variables are used.

## Approach 2: Optimized Prefix Sum Parity

The optimized approach uses the fact that the parity of a subarray sum depends only on the parity of two prefix sums.

Let the prefix sum ending at index `i` be `prefix[i]`. The sum of a subarray from index `j + 1` to `i` is:

```text
prefix[i] - prefix[j]
```

This difference is odd exactly when one prefix sum is odd and the other is even.

### Key Observation

Maintain two counts:

- `odd`: number of previous prefix sums that are odd.
- `even`: number of previous prefix sums that are even.

Initially:

```text
odd = 0
even = 1
```

The initial even prefix represents the empty prefix before the array starts. It allows a subarray beginning at index 0 to be counted whenever the current prefix sum is odd.

### Algorithm

For each element:

1. Add the current element to the running prefix sum.
2. If the prefix sum is even:
   - A subarray ending here has an odd sum when it starts after an odd prefix.
   - Add `odd` to the answer.
   - Increment `even`.
3. If the prefix sum is odd:
   - A subarray ending here has an odd sum when it starts after an even prefix.
   - Add `even` to the answer.
   - Increment `odd`.
4. Keep the answer modulo `10^9 + 7`.

This counts all odd-sum subarrays in a single traversal without explicitly generating them.

### Complexity Analysis

- **Time Complexity:** `O(n)` — the array is traversed once.
- **Auxiliary Space Complexity:** `O(1)` — only the running sum, answer, and two parity counts are maintained.

## C++ Solution

See [solution.cpp](./solution.cpp). The optimized prefix-parity implementation is active, and the brute-force implementation is preserved as a commented alternative.

## Approach Comparison

| Approach | Time Complexity | Auxiliary Space |
|---|---:|---:|
| Brute Force | `O(n^2)` | `O(1)` |
| Prefix Sum Parity | `O(n)` | `O(1)` |

## Key Takeaway

A subarray sum is odd when its two boundary prefix sums have different parity. Counting how many odd and even prefix sums have appeared so far eliminates the need to enumerate every subarray, reducing the solution from quadratic to linear time.
