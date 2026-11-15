class Solution {
    const int M = 1e9 + 7;

public:
    // Optimized: Prefix Sum Parity
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int odd = 0, even = 1;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum % 2 == 0) {
                ans = (ans + odd) % M;
                even++;
            } else {
                ans = (ans + even) % M;
                odd++;
            }
        }

        return ans;
    }

    // Brute Force
    // int numOfSubarrays(vector<int>& nums) {
    //     int n = nums.size();
    //     int ans = 0;
    //
    //     for (int i = 0; i < n; i++) {
    //         int sum = 0;
    //         for (int j = i; j < n; j++) {
    //             sum += nums[j];
    //             if (sum % 2 != 0)
    //                 ans++;
    //         }
    //         ans %= M;
    //     }
    //
    //     return ans;
    // }
};