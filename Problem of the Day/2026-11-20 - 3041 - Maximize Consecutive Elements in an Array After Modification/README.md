# 3041. Maximize Consecutive Elements in an Array After Modification

**LeetCode:** [Maximize Consecutive Elements in an Array After Modification](https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/)

## Problem Summary
Given an array, each element can be increased by at most one. Find the maximum number of selected elements that can form consecutive integer values after these modifications.

## Approach: Sorting + Dynamic Programming
Sort the array so that values are processed in non-decreasing order. Maintain a hash map `dp`, where `dp[x]` represents the best length of a chain ending at value `x`.

For each value `num`, consider both possibilities:
- Leave it as `num`: extend a chain ending at `num - 1`, updating `dp[num]`.
- Increase it to `num + 1`: extend a chain ending at `num`, updating `dp[num + 1]`.

Update the answer after considering both states.

## Algorithm
1. Sort `nums`.
2. Initialize an unordered map `dp` to store chain lengths by ending value.
3. For each `num` in sorted order:
   - Set `dp[num + 1] = dp[num] + 1`.
   - Set `dp[num] = dp[num - 1] + 1`.
   - Update the maximum from both states.
4. Return the maximum chain length.

## Complexity
- **Time:** `O(n log n)` average, dominated by sorting and hash map operations.
- **Space:** `O(n)` for the dynamic programming hash map.

## Key Takeaway
Sorting enables a left-to-right dynamic programming strategy. Each element can contribute to a chain ending at its original value or at one greater, and the hash map stores the best chain length for each ending value.
