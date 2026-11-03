# 3736. Minimum Moves to Equal Array Elements III

- **Date:** 2026-11-03
- **Platform:** [LeetCode](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/?envType=daily-question&envId=2026-11-03)
- **Difficulty:** Easy
- **Topics:** Array, Math

## Problem

You are given an integer array `nums`. In one move, you may increase any single element by 1. Return the minimum number of moves required to make all elements equal.

## Approach: Find the Maximum

Since an operation can only increase an element, the final common value cannot be smaller than the current maximum.

The best target is therefore the maximum element:

1. Find the maximum value `mx` in the array.
2. Increase every other element until it reaches `mx`.
3. Add all differences `mx - nums[i]` to get the minimum number of moves.

There is no need to sort the array. A single traversal finds the maximum, and another traversal calculates the required increments.

## C++ Solution

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = nums[0];

        for (int &i : nums) {
            mx = max(i, mx);
        }

        int ans = 0;
        for (int &i : nums) {
            ans += (mx - i);
        }

        return ans;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(n)` — two linear traversals of the array.
- **Space Complexity:** `O(1)` — only a few variables are used.

## Key Takeaway

When every operation can only increase an element, the optimal common target is the **maximum element**. The answer is:

`sum(max(nums) - nums[i])`

This is different from problems where you can increment or decrement elements, where the median is the optimal target.

---

*One problem a day. Keep learning, keep improving, and keep showing up. 🚀*
