# 3411. Maximum Subarray With Equal Products

**LeetCode:** [Maximum Subarray With Equal Products](https://leetcode.com/problems/maximum-subarray-with-equal-products/)

## Problem Summary
Find the maximum length of a contiguous subarray whose product is equal to the product of its least common multiple (LCM) and greatest common divisor (GCD).

## Approach: Brute Force + Incremental GCD and LCM
Enumerate every possible starting index and extend the subarray one element at a time. Maintain three values for the current subarray:
- `prod`: product of all its elements.
- `g`: GCD of all its elements.
- `l`: LCM of all its elements.

When a new element is included, update these values incrementally:
- Multiply `prod` by the new element.
- Update GCD using the Euclidean algorithm.
- Update LCM using `(a / gcd(a, b)) * b`.

For each subarray, check whether `prod == l * g`. If true, update the maximum length.

## Algorithm
1. Iterate over each starting index `i`.
2. Initialize product to 1, GCD to 0, and LCM to 1.
3. Extend the ending index `j` from `i` to the end:
   - Update product, GCD, and LCM with `nums[j]`.
   - If product equals LCM multiplied by GCD, update the answer with the current subarray length.
4. Return the maximum valid length.

## Complexity
- **Time:** `O(n^2 log M)` where `M` is the maximum value involved in the GCD/LCM updates. There are `O(n^2)` subarrays, with GCD/LCM updates taking logarithmic time.
- **Auxiliary Space:** `O(1)`.

## Key Takeaway
A brute-force enumeration can be made efficient by maintaining product, GCD, and LCM incrementally instead of recalculating them for every subarray.

## Implementation Note
The submitted code uses `u_int` for the product. Ensure this type is supported by the judge/compiler and that the product range is safe for the problem constraints. A wider integer type such as `long long` may be appropriate if the constraints require it.
