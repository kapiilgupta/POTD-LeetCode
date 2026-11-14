class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> pre(n, 0);
        pre[0] = nums[0];

        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int len = l; len <= r && i + len <= n; len++) {
                int end = i + len - 1;
                int sum = pre[end] - (i > 0 ? pre[i - 1] : 0);

                if (sum > 0)
                    ans = min(ans, sum);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};