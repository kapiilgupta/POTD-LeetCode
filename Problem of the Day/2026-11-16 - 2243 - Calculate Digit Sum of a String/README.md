# 2243. Calculate Digit Sum of a String

**Date:** November 16, 2026  
**LeetCode:** [2243. Calculate Digit Sum of a String](https://leetcode.com/problems/calculate-digit-sum-of-a-string/)

## Problem Summary

Given a numeric string `s` and an integer `k`, repeatedly split the string into consecutive groups of `k` characters (the final group may contain fewer than `k` characters). For each group, calculate the sum of its digits and concatenate the resulting sums to form a new string.

Repeat this process until the length of the string is less than or equal to `k`, then return the final string.

## Approach: Repeated Grouping and Digit Sum

The solution simulates the operation exactly as described in the problem.

### Algorithm

1. Continue processing while the length of `s` is greater than `k`.
2. For each round, initialize a running digit sum and an empty result string.
3. Traverse the current string:
   - Whenever the index is a non-zero multiple of `k`, append the previous group's sum to the result string and reset the running sum.
   - Add the current character's numeric value to the running sum using `s[i] - '0'`.
4. After the traversal, append the sum of the final group.
5. Replace `s` with the newly constructed string and repeat if its length is still greater than `k`.
6. Return `s` when the stopping condition is reached.

## C++ Solution

See [solution.cpp](./solution.cpp) for the complete implementation.

## Complexity Analysis

Let `n` be the initial length of the string and `k` be the group size.

- **Time Complexity:** `O(n log_k n)` for `k > 1). Each round processes the current string once, and its length shrinks by a factor of approximately `k`. More precisely, the total work is proportional to `n + n/k + n/k^2 + ...`, which is `O(n)` for fixed `k > 1`.
- **Auxiliary Space Complexity:** `O(n)` for the newly constructed string in a processing round.

## Key Takeaway

Simulate repeated transformations using a fresh result string for each round. Group boundaries can be identified with the index modulo `k`, making it simple to calculate each group's digit sum in one traversal.
