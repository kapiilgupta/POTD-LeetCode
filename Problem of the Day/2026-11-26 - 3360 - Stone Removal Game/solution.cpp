class Solution {
public:
    bool helper(int n, int take){
        return n >= take && !helper(n-take, take-1);
    }

    bool canAliceWin(int n) {
        return helper(n, 10);
    }
    
    // bool canAliceWin(int n) {
    //     if(n < 10) return false;
    //     else if(n > 10 && n < 19) return true;
    //     else if(n >= 19 && n < 27) return false;
    //     else if(n >= 27 && n < 34) return true;
    //     else if(n >= 34 && n < 40) return false;
    //     else if(n >= 40 && n < 45) return true;
    //     else if(n >= 45 && n < 49) return false;
    //     return true;
    // }
};