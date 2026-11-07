# 1882. Process Tasks Using Servers

**Date:** November 7, 2026  
**Platform:** [LeetCode](https://leetcode.com/problems/process-tasks-using-servers/)  
**Difficulty:** Medium  
**Topic:** Priority Queue, Greedy, Simulation

## Problem Summary

We are given servers with different weights and a list of tasks. Task `j` arrives at time `j` and takes `tasks[j]` units of time to complete.

For each task, assign an available server with the smallest weight. If multiple servers have the same weight, choose the one with the smallest index. If no server is available, the task waits until a server becomes free. Return the server index assigned to every task.

## Approach: Two Min-Heaps

We use two min-heaps to efficiently track available and busy servers.

1. **Available server heap (`free`):** Stores `{weight, index}`. The min-heap automatically selects the server with the smallest weight, breaking ties by the smallest index.
2. **Busy server heap (`busy`):** Stores `{finishTime, weight, index}`. It gives us the server that becomes available earliest.

### Processing each task

For every task at index `j`:

1. Move every busy server whose finish time is less than or equal to `j` into the available heap.
2. If at least one server is available, choose the top server from `free` and start the task at time `j`.
3. If no server is available, advance the task's start time to the earliest finish time in `busy`.
4. When waiting is necessary, move **all** servers that finish at that same earliest time into `free`. This is important because the correct choice must still follow the weight and index priority among all servers available at that time.
5. Assign the task to the top server and push it back into `busy` with finish time `startTime + tasks[j]`.

The heaps compare pairs/triples lexicographically, so the required tie-breaking rules are handled automatically.

## Complexity Analysis

Let:
- `n` be the number of servers.
- `m` be the number of tasks.

**Time Complexity:** `O((n + m) log n)`

- Building the available-server heap takes `O(n)`.
- Each task causes a constant number of heap operations.
- Each server moves between the heaps as tasks are processed, with heap operations taking `O(log n)`.

**Space Complexity:** `O(n + m)`

- The two heaps together store at most `n` servers: `O(n)`.
- The answer array stores `m` assigned server indices: `O(m)`.

## Key Takeaway

Using two min-heaps separates server selection from server availability:

- Order available servers by **weight, then index**.
- Order busy servers by **finish time, then weight, then index**.
- When a task has to wait, release every server that becomes free at the earliest finish time before selecting one.

This handles both server-priority tie-breaking and simultaneous server availability correctly.
