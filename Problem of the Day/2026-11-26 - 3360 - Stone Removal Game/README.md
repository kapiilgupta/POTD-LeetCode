# 3360. Stone Removal Game

**LeetCode:** [Stone Removal Game](https://leetcode.com/problems/stone-removal-game/)

## Problem Summary
Alice and Bob take turns removing stones from a pile. Alice starts and must remove exactly 10 stones. On each following turn, the required number of stones decreases by one: 9, then 8, then 7, and so on. A player who cannot make the required move loses. Determine whether Alice wins.

## Approach 1: Recursive Game Simulation (Minimax)

The recursive function `helper(n, take)` answers whether the player whose turn it is can force a win when:
- `n` stones remain.
- The player must remove exactly `take` stones.

### Recurrence
A player can make a move only when `n >= take`. After removing those stones, the opponent receives `n - take` stones and must remove `take - 1`.

The current player wins exactly when the opponent loses from that next state:

`helper(n, take) = (n >= take) && !helper(n - take, take - 1)`

If there are not enough stones, the expression evaluates to false, meaning the current player cannot move and loses.

### Step-by-step flow
1. Start with `helper(n, 10)`, because Alice must remove 10 stones first.
2. Check whether the current pile contains enough stones for the required move.
3. If it does, recursively evaluate the opponent's state after removing the required number.
4. Negate the opponent's result: if the opponent cannot win, the current player wins.
5. Return the result for Alice.

## Approach 2: Iterative Simulation (Alternative)
The commented-out range checks in the submitted code represent a pattern of winning and losing intervals. A more direct iterative simulation is:
1. Set `take = 10` and `aliceTurn = true`.
2. While `n >= take`, subtract `take`, decrease `take` by one, and switch the turn.
3. When the next player cannot move, the previous player won. Equivalently, the winner is determined by whether the number of successful removals is odd.

The submitted active implementation uses recursion; this iterative method is included here to explain the same game process without changing the submitted solution.

## Complexity Analysis
The required removal count decreases from 10 toward 1, so there can be at most 10 recursive calls under the problem constraints.

- **Time:** `O(10) = O(1)` — at most a fixed number of game moves.
- **Auxiliary Space:** `O(10) = O(1)` — recursion depth is bounded by the same fixed number of moves.

## Important Constraint Note
The recursive implementation has no explicit base case for `take == 0`. This is safe for the original problem's constraint `1 <= n <= 50`: the total number of stones needed to complete removals from 10 down through 2 is 54, so a valid input cannot reach a state requiring a removal of 1 or 0. If the input constraint were extended, an explicit stopping condition such as `if (take == 0) return false;` should be added.

## Key Takeaway
In a two-player turn-based game, a state is winning if at least one legal move leads to a losing state for the opponent. This naturally gives a recursive negation: make a valid move, then negate the result of the next player's state.
