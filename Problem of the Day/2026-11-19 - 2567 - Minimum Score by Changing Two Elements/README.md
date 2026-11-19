# 2567. Minimum Score by Changing Two Elements

**LeetCode:** [Minimum Score by Changing Two Elements](https://leetcode.com/problems/minimum-score-by-changing-two-elements/)

## Problem Summary
Given an array, change at most two elements to any values. Minimize the difference between the maximum and minimum elements after the changes.

## Approach: Sorting + Three Cases
Sort the array. Since we can modify two elements, the optimal answer can be obtained by eliminating the effect of two elements from one side or splitting the changes across both sides. After sorting, only three ranges need to be considered:

1. Change the two smallest elements: the remaining range is `nums[n - 1] - nums[2]`.
2. Change the two largest elements: the remaining range is `nums[n - 3] - nums[0]`.
3. Change one smallest and one largest element: the remaining range is `nums[n - 2] - nums[1]`.

Take the minimum of these three values. If the array has exactly three elements, both changes can make all three values equal, so the answer is `0`.

## Algorithm
1. If `n == 3`, return `0`.
2. Sort `nums` in ascending order.
3. Calculate the three possible ranges listed above.
4. Return the minimum range.

## Complexity
- **Time:** `O(n log n)` for sorting.
- **Auxiliary Space:** `O(1)` excluding sorting's implementation-dependent stack space.

## Key Takeaway
After sorting, the optimal result can be found by checking only three configurations of the two changes rather than trying every possible pair.
