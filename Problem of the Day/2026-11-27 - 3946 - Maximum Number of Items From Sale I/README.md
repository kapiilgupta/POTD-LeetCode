# 3946. Maximum Number of Items From Sale I

**LeetCode:** [Maximum Number of Items From Sale I](https://leetcode.com/problems/maximum-number-of-items-from-sale-i/)

## Problem Summary
Given a list of sale items and a budget, determine the maximum number of items that can be obtained. Each item is represented by its identifier and price. The solution uses the divisibility relationship between identifiers to precompute how many additional items are associated with choosing each item, then applies memoized recursion to make the budget decisions.

## Approach: Precomputation + 0/1 Knapsack (Top-Down DP)

The solution has two main stages.

### 1. Precompute the Number of Copies

For every item `i`, iterate over all other items `j` and check:

`items[j][0] % items[i][0] == 0`

If this condition is true, the identifier of item `j` is divisible by the identifier of item `i`. Increment `copies[i]`.

Therefore, `copies[i]` stores the number of additional items associated with selecting item `i` according to the divisibility rule. The total contribution when taking item `i` is:

`1 + copies[i]`

The same preprocessing loop also finds `minPrice`, the minimum price among all items.

### 2. Memoized Recursive DP

The state is:

`dfs(n, budget)`

It represents the maximum number of items obtainable by considering the first `n` entries of `items` with the given remaining budget.

For the last available item, there are two choices.

**Take the item**
- This choice is allowed only when its price is no greater than the remaining budget.
- Subtract its price from the budget.
- Add one for the selected item and add its precomputed associated copies.
- Solve the remaining problem using the first `n - 1` items.

`take = 1 + copies[n - 1] + dfs(n - 1, budget - price, ...)`

**Skip the item**
- Do not spend any budget on it.
- Continue with the first `n - 1` items and the same budget.

`skip = dfs(n - 1, budget, ...)`

Store the better of these choices in `dp[n][budget]` so that each state is computed only once.

### 3. Base Case

When `n == 0`, no more listed items remain to be considered. The implementation returns:

`budget / minPrice`

This accounts for as many additional items as the remaining budget can purchase at the minimum item price, as modelled by the submitted solution.

## Algorithm Walkthrough

1. Find the number of items, `n`.
2. Create a memoization table of size `(n + 1) x (budget + 1)`, initialized to `-1`.
3. For each item, count the other item identifiers divisible by its identifier and store the count in `copies`.
4. Track the minimum item price in `minPrice`.
5. Call `dfs(n, budget, minPrice, items, dp, copies)`.
6. At each DP state, compare taking the current item (when affordable) against skipping it.
7. Return the maximum count found.

## What Does the Function Return?

`maximumSaleItems` returns a single integer: the maximum number of items the algorithm can obtain under the given budget and sale rules. The DP maximizes the total contribution from the take/skip decisions, while the base case accounts for the remaining budget using the minimum price.

## Complexity Analysis

Let:
- `n` = number of items.
- `B` = the initial budget.

**Precomputation**
- The nested loops examine every pair of items: `O(n^2)` time.
- The `copies` array takes `O(n)` space.

**Memoized DP**
- There are at most `(n + 1) * (B + 1)` states.
- Each state performs constant work apart from its two recursive transitions.
- DP time: `O(nB)`.
- DP table space: `O(nB)`.
- Recursion stack: `O(n)`.

**Overall**
- **Time Complexity:** `O(n^2 + nB)`.
- **Auxiliary Space Complexity:** `O(nB)` for the DP table, plus `O(n)` for the copies array and recursion stack.

## Key Takeaway

This solution combines a pairwise divisibility precomputation with the classic take-or-skip structure of 0/1 knapsack. Precomputing each item's additional contribution keeps the recursive DP transition simple, and memoization avoids solving the same `(n, budget)` state repeatedly.
