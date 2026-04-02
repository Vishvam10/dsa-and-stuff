class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1) return s;

        // cols1 = n / numRows and then 
        // (numRows - 2) cols every n / numRows times
        // ... hmm, ignore whitespace ... then none of this matters and it's
        // a matter of modulo and direction reversals
        int n = s.length();
        vector<string> res(nRows);
        string ans;
        int cur = 0, dir = 1;
        for(int i = 0; i < n; ++i) {
            res[cur].push_back(s[i]);
            if(cur == 0) dir = 1;
            else if(cur == nRows - 1) dir = -1;
            cur += dir;
        }
        for(const string& s : res) ans += s;
        return ans;
        
    }
};