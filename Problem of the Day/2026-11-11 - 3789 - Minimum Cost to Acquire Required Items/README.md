# 3789. Minimum Cost to Acquire Required Items

**Date:** November 11, 2026  
**LeetCode:** [3789. Minimum Cost to Acquire Required Items](https://leetcode.com/problems/minimum-cost-to-acquire-required-items/)

## Problem Summary

We need to acquire at least `n1` units of item 1 and `n2` units of item 2. We can buy item 1 alone for `c1`, item 2 alone for `c2`, or a combined pack containing one of each for `cb`. Find the minimum total cost.

## Approach: Greedy

The combined pack can satisfy one unit of both requirements. We handle the overlapping requirements first, then purchase whatever remains.

### 1. Handle paired requirements

The number of units that both requirements have in common is:

```text
pairs = min(n1, n2)
```

For each pair, compare the combined pack with purchasing both items separately:

```text
costPairs = pairs * min(cb, c1 + c2)
```

This always chooses the cheaper way to satisfy one unit of each item.

### 2. Handle the remaining units

After satisfying the common portion:

```text
rem1 = n1 - pairs
rem2 = n2 - pairs
```

Only one of these remainders can be positive. For each remaining unit, compare its individual price with the combined-pack price. Even if the combined pack provides an extra unit of the other item, it may still be cheaper:

```text
costRem = rem1 * min(c1, cb)
       + rem2 * min(c2, cb)
```

The answer is `costPairs + costRem`.

## C++ Solution

The implementation is available in [solution.cpp](./solution.cpp). `long long` is used for the accumulated costs and products to avoid overflow.

## Complexity Analysis

- **Time Complexity:** `O(1)` — a constant number of arithmetic operations and comparisons.
- **Auxiliary Space Complexity:** `O(1)` — only a fixed number of variables are used.

## Key Takeaway

For the overlapping part of two requirements, compare a combined purchase against the sum of separate purchases. For any leftover requirement, compare the combined pack against the corresponding single-item purchase too. These greedy comparisons produce the minimum cost in constant time.
