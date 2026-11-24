class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    int lcm(int a, int b){
        return (a / gcd(a,b)) * b ;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        
        for(int i = 0 ; i < n-1; i++){
            u_int prod = 1, g = 0, l = 1;

            for(int j = i; j < n ; j++){
                prod *= nums[j];
                l = lcm(l, nums[j]);
                g = gcd(g, nums[j]);

                if(prod == l*g) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};