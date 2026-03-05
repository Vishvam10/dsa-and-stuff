class Solution {
    public:
        int minOperations(string s) {
            // 0 0 0 1 1 1 1 
            // 1 0 1 0 1 0 1 (OR) 0 1 0 1 0 1 0
            // so min of these 2 ... can't do bitmask as n is huge
            int n = s.length();
            int a = 0, b = 0;
            char cur1 = '0', cur2 = '1';
    
            for(int i = 0; i < n; ++i) {
                if(s[i] != cur1) a++;
                if(s[i] != cur2) b++;
                cur1 = (cur1 == '0') ? '1' : '0';
                cur2 = (cur2 == '0') ? '1' : '0';
            }
    
            return min(a, b);
        }
    };