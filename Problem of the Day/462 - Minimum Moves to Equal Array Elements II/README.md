# 462. Minimum Moves to Equal Array Elements II

- **Date added:** 2026-11-02
- **Platform:** [LeetCode](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)
- **Difficulty:** Medium
- **Topic:** Array, Sorting, Math

## Problem

Given an integer array `nums`, return the minimum number of moves required to make all array elements equal. In one move, you can increment or decrement an element by 1.

## Approach: Sorting + Median

The key observation is that the **median minimizes the sum of absolute differences** from all elements.

1. Sort the array.
2. Select the middle element, `nums[n / 2]`, as the target.
3. Add the absolute difference between every element and the target.

Choosing the median balances the number of elements on either side, giving the minimum total number of increments and decrements.

## C++ Solution

See [`solution.cpp`](solution.cpp).

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int median = nums[n / 2];

        long long ans = 0;
        for (int x : nums) {
            ans += abs(1LL * median - x);
        }

        return static_cast<int>(ans);
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(n log n)` — sorting dominates; the final traversal is `O(n)`.
- **Space Complexity:** `O(1)` auxiliary space for the algorithm, excluding the sorting implementation's internal stack.

## Key Takeaway

When minimizing the **sum of absolute distances**, think **median**. This is a useful pattern to recognize in array and optimization problems.

---

*Show up, solve the problem, understand the pattern, and keep moving. One problem at a time. 🚀*
