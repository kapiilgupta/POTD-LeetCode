# 1606. Find Servers That Handled Most Number of Requests

- **Date:** November 9, 2026
- **Platform:** [LeetCode](https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/)
- **Difficulty:** Hard
- **Topics:** Ordered Set, Priority Queue, Simulation

## Problem Summary

There are `k` servers numbered from `0` to `k - 1`. Requests arrive in the order given by `arrival`, and request `i` takes `load[i]` time to process.

A request is assigned to the available server with the smallest index that is at least `i % k`. If no such server exists, the search wraps around to the smallest available server. If every server is busy, the request is dropped.

Return the server or servers that handled the greatest number of requests, in increasing order.

## Approach: Ordered Set + Min-Heap

We maintain two data structures:

1. **Available servers (`set<int>`):** Stores the IDs of servers that are currently free. Since a set is ordered, `lower_bound(i % k)` finds the smallest available server ID greater than or equal to the preferred server.
2. **Busy servers (min-heap):** Stores `{finishTime, serverId}`. The server with the earliest finish time is at the top.

### Processing each request

For each request `i` arriving at time `arrival[i]`:

1. Release all busy servers whose finish time is less than or equal to the current arrival time. Insert their IDs into the available set.
2. If the available set is empty, drop the request and continue.
3. Calculate the preferred server ID as `i % k`.
4. Use `lower_bound(i % k)` to find the first available server with an ID at least as large as the preferred ID.
5. If the iterator reaches the end, wrap around to `available_servers.begin()`.
6. Assign the request to that server, remove it from the available set, and push its finish time (`arrival[i] + load[i]`) into the busy-server heap.
7. Increment the selected server's request count.

After processing all requests, find the maximum request count and collect every server whose count equals that maximum.

## Complexity Analysis

Let `n` be the number of requests and `k` be the number of servers.

- **Time Complexity:** `O((n + k) log k)`
  - Initializing the available set takes `O(k log k)`.
  - Each request performs heap and ordered-set operations, each taking `O(log k)`.
  - Finding the busiest servers takes `O(k)`.
- **Space Complexity:** `O(k)` for the available set, busy-server heap, and request-count array.

## Key Takeaway

Use an **ordered set** when you need the smallest available value satisfying a lower-bound condition, and a **min-heap** when you repeatedly need to process the item that becomes available earliest. Together, they efficiently simulate server assignment with wrap-around selection.
