# 3693. Climbing Stairs II

- **Date:** November 10, 2026 (Today's POTD)
- **Platform:** [LeetCode](https://leetcode.com/problems/climbing-stairs-ii/)
- **Difficulty:** Medium
- **Topics:** Dynamic Programming, Recursion, Memoization, Tabulation

## Problem Summary

You are at the bottom of a staircase with `n` steps. From position `i`, you can jump either 1, 2, or 3 steps forward.

If you jump from position `i` to position `j`, the cost of that jump is:

`costs[j - 1] + (j - i) * (j - i)`

The goal is to reach position `n` with the minimum possible total cost. Reaching position `n` ends the journey, so no additional cost is paid there.

This solution contains both **Top-Down DP (Recursion + Memoization)** and **Bottom-Up DP (Tabulation)**.

## Approach 1: Recursion with Memoization (Top-Down DP)

### Idea

Define `helper(i)` as the minimum cost required to reach step `n` when currently standing at step `i`.

At every position, we have up to three choices:

- Jump 1 step: move to `i + 1`
- Jump 2 steps: move to `i + 2`
- Jump 3 steps: move to `i + 3`

For each valid jump to position `j`, calculate:

`costs[j - 1] + (j - i)^2 + helper(j)`

Take the minimum among the valid choices.

### Base Case

When `i == n`, we have reached the destination, so the remaining cost is `0`.

### Memoization

Use a `dp` array initialized with `-1`. If the answer for a position has already been computed, return it instead of solving the same subproblem again.

### Complexity

- **Time:** `O(n)` — each of the `n` positions is computed once, with at most 3 transitions per position.
- **Space:** `O(n)` — the DP array and recursion call stack.

## Approach 2: Bottom-Up DP (Tabulation)

### Idea

We use the same DP state, but solve the subproblems iteratively instead of recursively.

Let `dp[i]` represent the minimum cost to reach step `n` from step `i`.

Since every transition moves forward to a larger index, we can calculate the states in reverse order, from `n - 1` down to `0`.

### Steps

1. Create a `dp` array of size `n + 1`, initialized to `0`.
2. The destination state is `dp[n] = 0`, because no cost is needed once we reach the top.
3. Iterate from `i = n - 1` down to `0`.
4. For each position, try jumps of 1, 2, and 3 steps, provided the destination `j` does not exceed `n`.
5. For each valid jump, calculate:

   `dp[j] + costs[j - 1] + (j - i)^2`

6. Store the minimum of these choices in `dp[i]`.
7. Return `dp[0]`.

### Complexity

- **Time:** `O(n)` — each position considers at most 3 transitions.
- **Space:** `O(n)` — the DP array; no recursion stack is required.

## Top-Down vs Bottom-Up

| Feature | Memoization | Tabulation |
|---|---|---|
| Style | Recursive | Iterative |
| Direction | Starts at step 0 and explores forward | Computes from step n-1 backward |
| Base case | `helper(n) = 0` | `dp[n] = 0` |
| Time | `O(n)` | `O(n)` |
| Space | `O(n)` including recursion stack | `O(n)` |

## Key Takeaway

Both approaches use the same recurrence and have **O(n) time complexity** because each position has only three possible transitions.

- Use **memoization** when the recursive state definition makes the problem easier to understand.
- Use **tabulation** when you want to avoid recursion overhead and explicitly control the order in which states are computed.

The key DP skill is identifying the state, base case, and transitions before choosing top-down or bottom-up implementation.
