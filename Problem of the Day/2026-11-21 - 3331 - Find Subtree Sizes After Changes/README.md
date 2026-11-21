# 3331. Find Subtree Sizes After Changes

**LeetCode:** [Find Subtree Sizes After Changes](https://leetcode.com/problems/find-subtree-sizes-after-changes/)

## Problem Summary
Given a rooted tree and a character assigned to each node, reassign each node's parent to its nearest ancestor having the same character (when such an ancestor exists). Return the subtree size of every node in the resulting tree.

## Approach: DFS + Nearest Same-Character Ancestor Tracking
Build the original tree using an adjacency list. Perform a DFS from the root while maintaining `last[c]`, the most recently visited node on the current DFS path whose character is `c`. This is the nearest ancestor with that character for the current node.

At each node:
1. Save the previous value of `last[c]` as `nearestAncestor`.
2. Set `last[c]` to the current node before visiting children.
3. DFS through the children.
4. Restore `last[c]` on returning (backtracking), so sibling branches do not affect each other.
5. If a matching ancestor exists, update the node's parent to that ancestor; otherwise retain its original parent.
6. Add the node's accumulated subtree size to its new parent.

Because the children are processed before the node's size is added to its new parent, the size accumulation is postorder.

## Algorithm
- Construct the adjacency list from the original parent array.
- Initialize every subtree size to 1 and all entries in `last` to -1.
- DFS from node 0, maintaining and restoring nearest same-character ancestors.
- During DFS postorder, update parent relationships and accumulate subtree sizes.
- Return the accumulated subtree-size array.

## Complexity
- **Time:** `O(n)`, each node and edge is processed once.
- **Space:** `O(n)` for the adjacency list, DFS state, and subtree sizes (excluding recursion stack, which is also `O(n)` in the worst case).

## Key Takeaway
Tracking the most recent occurrence of each character along the current DFS path provides the nearest matching ancestor in constant time. Restoring this state during backtracking makes it correct across separate branches.
