# 2747. Count Zero Request Servers

- **Date:** 2026-11-06
- **Platform:** [LeetCode](https://leetcode.com/problems/count-zero-request-servers/)
- **Difficulty:** Medium
- **Topics:** Array, Sorting, Sliding Window, Two Pointers

## Problem

You are given `n` servers, request logs containing a server ID and a timestamp, a time interval `x`, and multiple query timestamps.

For each query time `t`, consider the inclusive interval `[t - x, t]`. Return the number of servers that received **zero requests** during that interval.

## Approach: Sorting + Offline Queries + Sliding Window

Instead of processing each query independently, sort the logs and queries by timestamp. This lets us maintain one moving window over the logs.

### 1. Sort the logs

Sort `logs` by timestamp (`logs[i][1]`) so requests can be added in chronological order.

### 2. Sort query indices

Create an array of original query indices and sort those indices according to their query timestamps. This processes queries in increasing order while preserving the original order for the final answer.

### 3. Maintain the active time window

For a query time `t`, the required interval is inclusive: `[t - x, t]`.

- Move the right pointer while the log timestamp is at most `t`. Add each request to its server's frequency.
- When a server's frequency changes from zero to one, increment `distinct`.
- Move the left pointer while the log timestamp is strictly less than `t - x`. Remove those requests from the active window.
- When a server's frequency becomes zero, decrement `distinct`.

The number of servers with no requests in the interval is `n - distinct`.

Store the result at the original query index so the returned vector matches the input query order.

## C++ Solution

See [`solution.cpp`](solution.cpp).

## Complexity Analysis

Let:
- `L` = number of request logs
- `Q` = number of queries
- `N` = number of servers

- **Sort logs:** `O(L log L)`
- **Sort query indices:** `O(Q log Q)`
- **Sliding-window processing:** `O(L + Q)`, since each log enters and leaves the window at most once.
- **Total Time:** `O(L log L + Q log Q + L + Q)`
- **Space:** `O(N + L + Q)` for server frequencies, sorted query indices, and results (excluding sorting stack space).

## Key Takeaway

For many range queries over timestamped events, consider **offline query processing**:

1. Sort events by time.
2. Sort queries while remembering their original indices.
3. Move two pointers to maintain the active interval.
4. Track frequencies to maintain the number of distinct active servers.

Pay close attention to interval boundaries. The window is inclusive, so requests at exactly `t - x` must remain included.

---

*Consistency is built one problem at a time. Keep learning, keep solving, and keep moving forward. 🚀*
