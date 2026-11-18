# 2914. Minimum Number of Changes to Make Binary String Beautiful

**Date:** November 18, 2026  
**LeetCode:** [2914. Minimum Number of Changes to Make Binary String Beautiful](https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/)

## Problem Summary

Given a binary string `s` of even length, make it beautiful using the minimum number of character changes.

A binary string is beautiful when it can be partitioned into contiguous substrings of even length, each containing only identical characters.

## Approach: Greedy (Process Adjacent Pairs)

The key observation is that the string can be divided into fixed adjacent pairs:

```text
(s[0], s[1]), (s[2], s[3]), (s[4], s[5]), ...
```

For the string to be beautiful, both characters in every such pair must be equal.

### Algorithm

1. Initialize the answer `ans = 0`.
2. Traverse the string using an index increment of 2.
3. Compare the current character with the next character.
4. If they are different, one character must be changed to make the pair equal. Increment `ans`.
5. Return the total number of changes.

Each pair can be handled independently, and changing either one of its two different characters is sufficient. Therefore, counting mismatched pairs gives the minimum number of changes.

## C++ Solution

See [solution.cpp](./solution.cpp) for the implementation.

## Complexity Analysis

Let `n` be the length of the string.

- **Time Complexity:** `O(n)` — each character is visited exactly once as part of a pair.
- **Auxiliary Space Complexity:** `O(1)` — only the answer variable is used.

## Key Takeaway

When a binary string must be partitioned into even-length groups of identical characters, every fixed adjacent pair must contain equal bits. A single greedy pass that counts mismatched pairs gives the minimum number of changes.
