# 3947. Maximum Number of Items From Sale II

**LeetCode:** [Maximum Number of Items From Sale II](https://leetcode.com/problems/maximum-number-of-items-from-sale-ii/?envId=2026-11-28&envType=daily-question)

**Difficulty:** Medium  
**Topics:** Greedy, Sorting, Number Theory, Counting

## Approach: Divisibility Preprocessing + Greedy

The key observation is that a purchased copy can provide one additional free item, but only while there is an eligible item type that has not already been received for free from that purchased item type.

For an item with factor `f` and price `p`, let `g` be the number of *other* items whose factors are divisible by `f`. Then:

- The first `g` purchased copies of this item type can each contribute **2 items**: one purchased item and one free item.
- Any further purchased copies contribute only **1 item** each.

So we can treat the first `g` copies as high-value purchases (2 items for price `p`), while ordinary copies have value 1.

## 1. Count the number of items for every factor

Create `cnt`, where `cnt[x]` stores how many items have factor exactly `x`.

Then calculate `mult[f]`, the number of items whose factors are multiples of `f`:

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
        mult[i] += cnt[j];
    }
}
```

This enumerates the multiples of every factor. For an item whose factor is `f`, the number of eligible *other* items is:

```cpp
int g = mult[f] - 1;
```

We subtract one to exclude the item itself.

## 2. Collect useful high-value purchases

If `g > 0`, this item type can provide free items. Store the pair:

```cpp
{price, g}
```

Here, `g` is the maximum number of copies of this type that can each earn a distinct free item.

Also track `minP`, the minimum price among all item types.

## 3. Greedily buy high-value copies

Sort the candidates by price in ascending order.

A high-value copy costs `p` and gives 2 items. The remaining budget could instead buy ordinary copies of the cheapest item, each costing `minP` and giving 1 item.

Therefore, a high-value copy is worth buying only when:

```cpp
p <= 2 * minP
```

If its price is greater than `2 * minP`, spending that same budget on the cheapest ordinary item gives more items. Since candidates are sorted by price, we can stop as soon as this condition fails.

For each candidate, buy as many high-value copies as possible, limited by both:
- Its available free-item matches `g`.
- The number of copies affordable with the remaining budget.

```cpp
long long can = min((long long)g, (B - spent) / p);
total += can * 2;
spent += can * p;
```

## 4. Spend the remaining budget

After processing all worthwhile high-value copies, use the remaining budget to buy as many copies as possible of the cheapest item:

```cpp
total += (B - spent) / minP;
```

Each of these contributes one purchased item.

## Complexity Analysis

Let `n` be the number of item types.

| Operation | Complexity |
|---|---:|
| Build the exact-factor frequency array | `O(n)` |
| Count all multiples for every factor | `O(n log n)` |
| Build the candidate list | `O(n)` |
| Sort candidates | `O(n log n)` |
| Greedy allocation | `O(n)` |

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(n)`

The multiples-counting loop takes harmonic-series time, since factor `i` visits approximately `n/i` multiples.

## Key Takeaway

The important optimization is to think in terms of **marginal value per purchase**:

- First `g` copies of an item type: 2 items for price `p`.
- Remaining copies: 1 item for price `p`.

Because every ordinary copy can be bought at the minimum price, only high-value copies costing at most twice that minimum price need to be considered. Sorting these candidates by price and processing them greedily gives an efficient solution without a budget-sized DP.
