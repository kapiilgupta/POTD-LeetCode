class Solution {
public:
    bool checkString(string s) {
        bool isB = false;
        for(char c: s){
            if(c == 'b') isB = true;
            if(isB && c == 'a') return false;
        }

        return true;
    }
};