# 1385. Find the Distance Value Between Two Arrays

- **Date:** 2026-11-05
- **Platform:** [LeetCode](https://leetcode.com/problems/find-the-distance-value-between-two-arrays/)
- **Difficulty:** Easy
- **Topics:** Array, Sorting, Binary Search

## Problem

Given two integer arrays `arr1` and `arr2`, and an integer `d`, find the distance value between the arrays.

An element `arr1[i]` is counted if there is **no** element `arr2[j]` such that:

`|arr1[i] - arr2[j]| <= d`

Return the number of elements in `arr1` that satisfy this condition.

## Approach 1: Sorting + Binary Search (Optimized)

Instead of comparing each element of `arr1` with every element of `arr2`, sort `arr2` and use `lower_bound`.

For a value `i` from `arr1`, an element of `arr2` violates the condition exactly when it lies in the interval `[i - d, i + d]`.

1. Sort `arr2`.
2. For each `i` in `arr1`, use `lower_bound(arr2.begin(), arr2.end(), i - d)` to find the first element that is at least `i - d`.
3. If this iterator exists and its value is at most `i + d`, a value in the forbidden interval exists, so do not count `i`.
4. Otherwise, increment the answer.

Because `lower_bound` returns the first element not less than the requested value, checking this one candidate is sufficient.

## C++ Solution

See [`solution.cpp`](solution.cpp).

```cpp
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int ans = 0;
        for (int &i : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), i - d);

            if (it != arr2.end() && *it <= i + d) continue;
            ans++;
        }

        return ans;
    }
};
```

## Complexity Analysis

Let `n = arr1.size()` and `m = arr2.size()`.

- **Sorting:** `O(m log m)`
- **Binary searches:** `O(n log m)`
- **Total Time:** `O(m log m + n log m)`
- **Auxiliary Space:** `O(1)` excluding the sorting implementation's internal stack.

## Approach 2: Brute Force

For every element in `arr1`, check every element in `arr2`. If any absolute difference is at most `d`, that element is not counted.

- **Time Complexity:** `O(n * m)`
- **Auxiliary Space:** `O(1)`

The brute-force implementation is also preserved as a comment in `solution.cpp`.

## Key Takeaway

When checking whether a sorted array contains any value inside a range, `lower_bound` can find the first possible candidate. One comparison then tells us whether that candidate lies inside the range.

**Sort once, search efficiently, and avoid unnecessary nested loops.**

---

*Consistency compounds. Keep solving, keep learning, and keep moving forward. 🚀*
