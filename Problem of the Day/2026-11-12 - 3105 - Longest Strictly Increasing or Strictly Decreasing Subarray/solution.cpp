class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1, ans = 1;

        for (int i = 1; i < nums.size(); i++) {
            inc = (nums[i - 1] < nums[i]) ? inc + 1 : 1;
            dec = (nums[i - 1] > nums[i]) ? dec + 1 : 1;

            ans = max({ans, inc, dec});
        }

        return ans;

        // Alternative approach: two separate passes

        // int inc = 1, curr = 1;
        // for (int i = 1; i < nums.size(); i++) {
        //     if (nums[i] > nums[i - 1]) {
        //         curr++;
        //         inc = max(inc, curr);
        //     } else {
        //         curr = 1;
        //     }
        // }

        // int dec = 1;
        // curr = 1;
        // for (int i = 1; i < nums.size(); i++) {
        //     if (nums[i] < nums[i - 1]) {
        //         curr++;
        //         dec = max(dec, curr);
        //     } else {
        //         curr = 1;
        //     }
        // }

        // return max(inc, dec);
    }
};