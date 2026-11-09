# 1267. Count Servers that Communicate

- **Date:** November 8, 2026 (Yesterday's POTD)
- **Platform:** [LeetCode](https://leetcode.com/problems/count-servers-that-communicate/)
- **Difficulty:** Medium
- **Topics:** Array, Matrix, Counting

## Problem Summary

We are given an `m x n` binary grid where `1` represents a server and `0` represents an empty cell.

A server can communicate with another server if they are in the same row or the same column. Return the number of servers that can communicate with at least one other server.

## Approach: Row and Column Frequency Counting

Instead of checking every server against every other server, count how many servers exist in each row and column.

1. Create a `row` array of size `m` and a `col` array of size `n`, both initialized to zero.
2. Traverse the grid once. Whenever a cell contains a server (`1`), increment its row count and column count.
3. Traverse the grid again. A server at `grid[i][j]` can communicate if either:
   - Its row contains more than one server (`row[i] > 1`), or
   - Its column contains more than one server (`col[j] > 1`).
4. Count every server satisfying either condition and return the answer.

The OR condition ensures that a server is counted only once, even if it can communicate through both its row and column.

## Complexity Analysis

Let `m` be the number of rows and `n` be the number of columns.

- **Time Complexity:** `O(m * n)` — we traverse the grid twice, and each traversal visits every cell once.
- **Space Complexity:** `O(m + n)` — the row and column frequency arrays require `m + n` additional space.

## Key Takeaway

When a matrix problem asks whether an element shares a row or column with other elements, precompute row and column frequencies. This avoids repeatedly scanning rows and columns for every server.

---

*One problem at a time. Understand the pattern, strengthen the fundamentals, and keep moving. 🚀*
