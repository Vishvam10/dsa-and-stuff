
class Solution {
public:

    int minInsertions(string s) {
        
        // dp[p1][p2] means the min. number of steps taken at (p1, p2)
        // to make a string a palindrome

        // dp[p1][p2] = IF s[p1] == s[p2] : dp[p1 + 1][p2 - 1]
        //              ELSE : min(dp[p1 + 1][p2], dp[p1][p2 - 1])
    
        // Base cases : dp[i][i] = 0 (single letter palindrome)
        // So, dp[i][j] depends on :
        //      - down : dp[p1 + 1][p2]
        //      - left : dp[p1][p2 - 1]
        //      - diag down left : dp[p1 + 1][p2 - 1]

        // So, start from bottom right corner to top left. 
        // For this case : if(p1 >= p2) return 0; we will just start
        // p2 from p1 + 1 so that it's always true

        int n = s.length();
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> cur(n, 0), nxt(n, 0);
        
        for(int i = n - 1; i >= 0; --i) {
            // dp[i][i]
            cur[i] = 0;
            for(int j = i + 1; j < n; ++j) {
                if(s[i] == s[j]) {
                    // dp[i][j] = dp[i + 1][j - 1]
                    cur[j] = nxt[j - 1];
                } else {
                    // dp[i][j] = min(dp[i + 1][j], dp[i][j - 1])
                    cur[j] = 1 + min(nxt[j], cur[j - 1]);
                }
            }
            // nxt = cur;

            // This is faster : O(1) pointer swap. NOTE : since the values
            // of cur in the next i iteration will be overwritted anyway,
            // we do this ... if for some reason, it doesn't, then obviously
            // we use nxt = cur (normal assignment)
            swap(nxt, cur)
        }

        return nxt[n - 1];
    }
};

class Solution {
public:

    int minInsertions(string s) {
        // p1 = 0 and p2 = n - 1
        // IF s[p1] == s[p2] : solve(p1 + 1, p2 - 1)
        // ELSE :
        //   - Insert at p1 and move p1 := 1 + solve(p1 + 1, p2)
        //   - Insert at p2 and move p2 := 1 + solve(p1, p2 - 1)

        // dp[p1][p2] means the min. number of steps taken at (p1, p2)
        // to make a string a palindrome

        // dp[p1][p2] = IF s[p1] == s[p2] : dp[p1 + 1][p2 - 1]
        //              ELSE : min(dp[p1 + 1][p2], dp[p1][p2 - 1])
    
        // Base cases : dp[i][i] = 0 (single letter palindrome)
        // So, dp[i][j] depends on :
        //      - down : dp[p1 + 1][p2]
        //      - left : dp[p1][p2 - 1]
        //      - diag down left : dp[p1 + 1][p2 - 1]

        // So, start from bottom right corner to top left. 
        // For this case : if(p1 >= p2) return 0; we will just start
        // p2 from p1 + 1 so that it's always true

        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i + 1; j < n; ++j) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

class Solution {
public:

    int solve(int p1, int p2,const string& s) {
        if(p1 >= p2) return 0;
        if(s[p1] == s[p2]) return solve(p1 + 1, p2 - 1, s);
        int atP1 = 1 + solve(p1 + 1, p2, s);
        int atP2 = 1 + solve(p1, p2 - 1, s);
        return min(atP1, atP2);
    }

    int minInsertions(string s) {
        // p1 = 0 and p2 = n - 1
        // IF s[p1] == s[p2] : solve(p1 + 1, p2 - 1)
        // ELSE :
        //   - Insert at p1 and move p1 := 1 + solve(p1 + 1, p2)
        //   - Insert at p2 and move p2 := 1 + solve(p1, p2 - 1)

        // NOTE : Insert at both p1 and p2 = insert at p1 then insert at p2
        // So, no need to have 2 + solve(p1 + 1, p2 - 1). Besides anyway, 
        // at a given point, we can make only 1 edit

        return solve(0, s.length() - 1, s);
    }
};