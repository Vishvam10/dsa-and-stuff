class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        if(n == 1) return (s[0] == '1');
        int res = 0; bool ans = false;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '1') {
                if(!ans) {
                    res++;
                } else {
                    return false;
                }
            } else {
                res = 0;
                ans = true;
            }
        }
        if(!ans && res > 0) return true;
        return ans;
    }   
};