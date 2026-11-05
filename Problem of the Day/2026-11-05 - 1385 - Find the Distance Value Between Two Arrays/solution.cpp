class Solution {
public:
    // Optimized using binary search
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int ans = 0;
        for (int &i : arr1) {
            // Find the first element >= i - d.
            auto it = lower_bound(arr2.begin(), arr2.end(), i - d);

            // If it exists and is <= i + d, a value is too close.
            if (it != arr2.end() && *it <= i + d) continue;

            ans++;
        }

        return ans;
    }

    // Brute force: O(n * m)
    // int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    //     int ans = 0;
    //     for (int i = 0; i < arr1.size(); i++) {
    //         bool isValid = true;
    //         for (int j = 0; j < arr2.size(); j++) {
    //             if (abs(arr1[i] - arr2[j]) <= d) {
    //                 isValid = false;
    //                 break;
    //             }
    //         }
    //         if (isValid) ans++;
    //     }
    //     return ans;
    // }
};
