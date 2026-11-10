class Solution {
public:
    // Recursion with Memoization
    int helper(vector<int>& costs, int i, int n, vector<int>& dp) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int cost = INT_MAX;

        int j = i + 1;
        if (j <= n) {
            cost = costs[j - 1] + (j - i) * (j - i)
                 + helper(costs, j, n, dp);
        }

        j = i + 2;
        if (j <= n) {
            cost = min(cost, costs[j - 1] + (j - i) * (j - i)
                             + helper(costs, j, n, dp));
        }

        j = i + 3;
        if (j <= n) {
            cost = min(cost, costs[j - 1] + (j - i) * (j - i)
                             + helper(costs, j, n, dp));
        }

        return dp[i] = cost;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        return helper(costs, 0, n, dp);
    }
};

/*
// Bottom-Up Dynamic Programming (Tabulation)
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int cost = INT_MAX;

            int j = i + 1;
            if (j <= n) {
                cost = dp[j] + costs[j - 1] + (j - i) * (j - i);
            }

            j = i + 2;
            if (j <= n) {
                cost = min(cost, dp[j] + costs[j - 1]
                                  + (j - i) * (j - i));
            }

            j = i + 3;
            if (j <= n) {
                cost = min(cost, dp[j] + costs[j - 1]
                                  + (j - i) * (j - i));
            }

            dp[i] = cost;
        }

        return dp[0];
    }
};
*/