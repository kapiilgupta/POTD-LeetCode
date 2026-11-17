# 2911. Minimum Changes to Make K Semi-palindromes

**Date:** November 17, 2026  
**LeetCode:** [2911. Minimum Changes to Make K Semi-palindromes](https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/)

## Problem Summary

Given a string `s` and an integer `k`, divide the string into exactly `k` non-empty contiguous substrings. Every substring must be a semi-palindrome, and we need to minimize the total number of character replacements required.

A substring is a semi-palindrome if there exists a proper divisor `d` of its length such that the characters at positions having the same remainder modulo `d` form a palindrome.

## Approach: Precomputation + Memoization (Top-Down DP)

The solution separates the problem into two subproblems:

1. Calculate the minimum changes needed to make any substring a semi-palindrome.
2. Use recursion with memoization to partition the complete string into exactly `k` valid substrings at minimum total cost.

### 1. Precompute substring cost on demand: `getCost(i, j)`

The function `getCost(i, j)` calculates the minimum number of replacements needed to make the substring `str[i...j]` a semi-palindrome.

Let the substring length be:

```text
len = j - i + 1
```

A valid `d` must be a proper divisor of `len`. The code checks every candidate `d` from 1 to `len - 1` and skips it when `len % d != 0`.

For a valid divisor:

- The substring is divided into `d` groups according to their positions modulo `d`.
- Each group is checked as a palindrome.
- The two pointers start at the corresponding group's first and last characters.
- If the characters differ, one replacement is needed.
- The pointers move inward by `d` positions.

The mismatch count gives the number of changes for that divisor. The minimum across all valid divisors is the cost of making the substring semi-palindromic.

The result is cached in `costMemo[i][j]`, avoiding repeated calculations for the same substring.

### 2. Partition using recursion: `solve(start, k)`

The function returns the minimum cost to partition the suffix beginning at `start` into exactly `k` semi-palindromic substrings.

**Base cases:**

- If `k == 0`, return 0 only when `start == n`; otherwise, the partition is invalid.
- Every semi-palindrome must have length at least 2. Therefore, if `start + 2 * k > n`, there are not enough characters left to form `k` valid parts, so return `INT_MAX`.

**Transitions:**

Try every possible ending index `end` starting from `start + 1`, ensuring the current substring has at least two characters.

For each split:

1. Calculate the minimum cost for the remaining suffix using `solve(end + 1, k - 1)`.
2. Skip the split if the remaining partition is invalid.
3. Otherwise, add the current substring's semi-palindrome cost, `getCost(start, end)`, to the remaining cost.
4. Keep the minimum total cost across all possible split positions.

The result is memoized in `memo[start][k]`.

### 3. Final answer

Initialize the string length and memoization tables in `minimumChanges`, then call:

```text
solve(0, k)
```

This finds the minimum number of changes needed to partition the entire string into exactly `k` semi-palindromes.

## C++ Solution

See [solution.cpp](./solution.cpp) for the complete implementation.

## Complexity Analysis

Let `n` be the length of the string.

- **Substring cost computation:** For one substring of length `L`, the code checks the proper divisors of `L`. For each divisor, it examines at most `L / 2` mirrored pairs in total. Thus, one uncached `getCost` call takes at most `O(L * number_of_divisors(L))`, bounded by `O(L^2)`.
- **DP states and transitions:** There are `O(nk)` states, and each state may try up to `O(n)` ending positions.
- **Overall time complexity:** A conservative upper bound is `O(k * n^4)), accounting for up to `O(n^2)` substring costs, each computed in `O(n^2)` time. The DP transition work is `O(kn^2)`.
- **Auxiliary Space Complexity:** `O(n^2 + nk)` for `costMemo`, `memo`, and the recursion stack (which is at most `O(n)`).

## Key Takeaway

Separate substring validity/cost from the partitioning decision. Memoizing the cost of each substring prevents recomputing its semi-palindrome transformations, while top-down DP explores possible split points and finds the minimum total cost.
