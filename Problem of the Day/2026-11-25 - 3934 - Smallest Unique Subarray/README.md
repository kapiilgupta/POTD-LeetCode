# 3934. Smallest Unique Subarray

**LeetCode:** [Smallest Unique Subarray](https://leetcode.com/problems/smallest-unique-subarray/)

## Problem Summary
Given an integer array, find the minimum length of a contiguous subarray that is not identical to any other subarray in the array. Two subarrays are identical when they have the same length and the same values in the same order.

## Approach: Binary Search + Rolling Hash + Sliding Window

The solution binary-searches the candidate subarray length. For a fixed length, it computes the rolling hash of every window and counts how often each hash occurs. If at least one hash occurs exactly once, a unique window of that length has been found.

### 1. Why Binary Search Works
The feasibility condition is monotonic:
- If a unique subarray of length `L` exists, extending that exact subarray by one adjacent element produces a longer subarray that also occurs only once.
- Therefore, if a unique subarray exists for length `L`, one exists for every larger length.
- If no unique subarray exists for length `L`, no smaller length can have one.

This allows binary search over lengths from `1` to `n`.

### 2. Polynomial Rolling Hash
For a fixed window, the code builds a polynomial hash from left to right:

`hash = (hash * base + nums[j]) % MOD`

The base is chosen as `max(nums) + 1`, and `MOD = 1,000,000,007`.

To move the window one position to the right, remove the contribution of its outgoing first element. Its positional multiplier is `base^(size-1)`, precomputed using binary exponentiation:

`hash = (hash - p * nums[i] % MOD + MOD) % MOD`

The next iteration appends the incoming element. Thus each window hash is updated in constant time after the initial power calculation.

### 3. Counting Window Hashes
The `check(nums, size, base)` function:
1. Computes `p = base^(size-1) % MOD`.
2. Slides a window of the requested size over the array.
3. Stores each window hash's frequency in an unordered map.
4. Returns true if any hash has frequency exactly one.

A hash frequency of one indicates a candidate unique subarray of that length.

### 4. Binary Search
- Start with `l = 1` and `r = n`.
- If `check` returns true for `mid`, record it and search smaller lengths.
- Otherwise, search larger lengths.
- Return the smallest feasible length.

## Code Walkthrough
- **`findPower(a, base)`:** Recursive binary exponentiation computes `a^base % MOD` in logarithmic time.
- **`check(nums, size, base)`:** Uses a fixed-size sliding window, rolling hash, and frequency map to test whether a unique window exists.
- **`smallestUniqueSubarray(nums)`:** Chooses the rolling-hash base and binary-searches for the minimum valid length.

## Complexity Analysis

Let `n` be the array length.

- **`findPower`:** `O(log n)` for a candidate window length.
- **`check`:** Expected `O(n)` time for sliding-window updates and unordered-map operations, plus `O(log n)` for the power calculation. It uses `O(n)` map space.
- **Binary search:** Performs `O(log n)` checks.

Overall:
- **Expected Time:** `O(n log n)`.
- **Auxiliary Space:** `O(n)` for the frequency map.

## Important Note: Hash Collisions
This implementation uses a single modular rolling hash. Different subarrays can theoretically produce the same hash modulo `MOD`. Therefore, the frequency map counts hash values rather than verifying exact subarray contents. The method is probabilistic in that sense; a collision can affect correctness. A double hash or exact comparison strategy can reduce or eliminate this risk.

## Key Takeaway
When a feasibility condition is monotonic, binary search can optimize the answer. Rolling hash makes each fixed-length window check efficient, while a sliding window and frequency map identify whether any window is unique.
