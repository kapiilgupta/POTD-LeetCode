class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int ans = 0;

        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;

        for (int num : nums) {
            dp[num+1] = dp[num] + 1;
            dp[num] = dp[num-1] + 1;
            ans = max({ans, dp[num], dp[num + 1]});
        }

        return ans;
    }
};