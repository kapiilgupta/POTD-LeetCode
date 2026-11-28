class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> cnt(n + 1, 0);
        for (auto &i: items) cnt[i[0]]++;

        vector<int> mult(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) mult[i] += cnt[j];
        }

        int minP = INT_MAX;
        vector<pair<int, int>> cand;
        for (auto &i: items) {
            int f = i[0], p = i[1];

            minP = min(minP, p);
            int g = mult[f] - 1;

            if (g > 0) cand.push_back({p, g});
        }

        sort(cand.begin(), cand.end());

        long long spent = 0, total = 0, B = budget;
        for (auto& [p, g]: cand) {
            if (p > 2LL * minP) break;

            long long can = min((long long)g, (B - spent) / p);

            total += can * 2;
            spent += can * p;
        }

        total += (B - spent) / minP;

        return (int)total;
    }
};