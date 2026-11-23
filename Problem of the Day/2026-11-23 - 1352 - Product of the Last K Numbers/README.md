# 1352. Product of the Last K Numbers

**LeetCode:** [Product of the Last K Numbers](https://leetcode.com/problems/product-of-the-last-k-numbers/)

## Problem Summary
Design a data structure that supports adding numbers to a stream and returning the product of the last `k` numbers.

## Approach: Prefix Products
Maintain a vector `pre` of prefix products for the numbers added since the most recent zero. Initialize it with `1` so that products can be calculated cleanly.

### Handling Zero
Whenever a zero is added, all products that include that zero become zero. Reset the prefix-product vector to `[1]`. This also makes any query asking for more numbers than have been added since the latest zero return zero.

### Querying the Last K Numbers
If `k` is at least the current prefix vector's size, the requested range includes a zero (or extends before the current zero-free segment), so return `0`.

Otherwise, use prefix-product division:
`product(last k) = pre.back() / pre[pre.size() - 1 - k]`.

## Algorithm
1. Start with `pre = [1]`.
2. For `add(num)`:
   - If `num == 0`, reset `pre` to `[1]`.
   - Otherwise append `pre.back() * num`.
3. For `getProduct(k)`:
   - If `k >= pre.size()`, return `0`.
   - Else return the quotient of the last prefix product by the prefix product immediately before the requested range.

## Complexity
- **add:** `O(1)` time.
- **getProduct:** `O(1)` time.
- **Space:** `O(n)` for the stored prefix products since the most recent zero.

## Key Takeaway
Prefix products let range products be answered in constant time through division. Resetting the prefix array at every zero avoids zero-division issues and makes zero-containing queries trivial.
