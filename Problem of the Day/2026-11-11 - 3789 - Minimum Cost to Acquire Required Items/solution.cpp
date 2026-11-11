class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        long long pairs = min(n1, n2);
        long long costPairs = pairs * min(cb, c1 + c2);

        long long rem1 = n1 - pairs;
        long long rem2 = n2 - pairs;

        long long costRem = rem1 * min(c1, cb) + rem2 * min(c2, cb);

        return costPairs + costRem;
    }
};