# 3420. Count Non-Decreasing Subarrays After K Operations

**Date:** November 13, 2026  
**LeetCode:** [3420. Count Non-Decreasing Subarrays After K Operations](https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/)

## Problem Summary

Given an integer array `nums` and an integer `k`, count the contiguous subarrays that can be made non-decreasing using at most `k` operations.

An operation increments an element by 1. The goal for each subarray is to determine the minimum number of increments needed to make its elements non-decreasing, then count it if that minimum is at most `k`.

## Approach: Prefix Sum + Monotonic Stack + Monotonic Deque + Sliding Window

The solution efficiently calculates the minimum number of operations for each candidate window. It combines prefix sums, next-greater-element preprocessing, and a sliding window whose maximum is maintained with a monotonic deque.

### 1. Prefix sums for range-sum queries

Build `cumSum`, where each position stores the sum of all elements from index 0 through that position.

The `rangeSum(i, j)` lambda returns the sum of any range in constant time:

```text
sum(i, j) = cumSum[j] - cumSum[i - 1]
```

The implementation handles the case `i == 0` separately and returns 0 for an empty range.

### 2. Find the next greater element

Use a monotonic stack to calculate `NGR[i]`, the index of the first element strictly greater than `nums[i]` to its right. If no such element exists, the value remains `n`.

When a new value is greater than the value at the stack's top index, it becomes that index's next greater element.

This preprocessing partitions the suffix into segments where the current value at the segment's start acts as the target height when making the segment non-decreasing.

### 3. Precompute operation costs

The `Operations` array stores the total number of increments required to raise the relevant next-greater-element segments through the end of the array.

For index `i`, let `m = NGR[i]`. The cost to raise every element in the segment `[i, m - 1]` to `nums[i]` is:

```text
segmentOperations =
    nums[i] * (m - i) - sum(i, m - 1)
```

The recurrence is:

```text
Operations[i] = segmentOperations + Operations[m]
```

It is computed from right to left so that `Operations[m]` is already available.

### 4. Sliding window with a monotonic deque

Use two pointers, `i` and `j`, to represent the current window `[i, j]`.

The deque stores indices in decreasing order of their corresponding values, with the maximum element at its front. When adding `nums[j]`, remove smaller values from the back before inserting the new index.

Let `m` be the index at the front of the deque. The number of increments required to make the current window non-decreasing is calculated as:

```text
operations =
    (Operations[i] - Operations[m])
    + nums[m] * (j - m + 1)
    - sum(m, j)
```

If this cost exceeds `k`, move the left pointer forward and remove the deque's front index when it falls outside the window. Continue until the current window needs at most `k` operations.

### 5. Count valid subarrays

Once the window `[i, j]` is valid, every suffix of this window ending at `j` is also valid. There are exactly:

```text
j - i + 1
```

such subarrays. Add this number to the answer, then expand the window by moving `j` forward.

## C++ Solution

See [solution.cpp](./solution.cpp) for the complete implementation.

## Complexity Analysis

Let `n` be the length of `nums`.

- **Time Complexity:** `O(n)`. Prefix sums, next-greater-element preprocessing, and operation-cost preprocessing each take linear time. In the sliding-window phase, every index is inserted into and removed from the deque at most once, and the two pointers move only forward.
- **Auxiliary Space Complexity:** `O(n)`. The prefix-sum array, next-greater-element array, operation-cost array, monotonic stack, and deque use linear space.

## Key Takeaway

Combining next-greater-element preprocessing with prefix sums lets us calculate the cost of making a window non-decreasing efficiently. A monotonic deque maintains the window maximum, while the sliding-window technique counts all valid subarrays in linear time.
