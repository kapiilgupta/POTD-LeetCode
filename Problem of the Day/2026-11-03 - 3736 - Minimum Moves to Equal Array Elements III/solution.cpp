class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = nums[0];
        for (int &i : nums) mx = max(i, mx);

        int ans = 0;
        for (int &i : nums) ans += (mx - i);

        return ans;
    }
};
