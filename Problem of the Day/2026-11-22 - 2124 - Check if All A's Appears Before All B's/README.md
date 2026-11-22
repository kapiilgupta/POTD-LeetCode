# 2124. Check if All A's Appears Before All B's

## Problem
Given a string containing only the characters `a` and `b`, check whether every `a` appears before every `b`. Return `true` if the string satisfies this condition, otherwise return `false`.

## Approach
- Maintain a boolean flag `isB`, initially `false), to track whether a `b` has appeared.
- When a `b` is encountered, set `isB` to `true).
- If an `a` appears after `isB` becomes `true), the order is violated, so return `false).
- If the scan finishes without finding such a violation, return `true).

## Complexity
- **Time Complexity:** O(n), where n is the length of the string. We scan the string once.
- **Space Complexity:** O(1), using only a boolean variable.

## Solution
See [solution.cpp](solution.cpp).
