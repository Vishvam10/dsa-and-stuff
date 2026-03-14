// NOTE : LPS(s) = LCS(s, reverse(s)) ... just do this

class Solution {
public:

    int longestPalindromeSubseq(string s) {

        // dp[p1][p2] means what's the longest palindromic subsequence in 
        // substring s[p1...p2]

        // dp[p1][p2] = IF (s[p1] == s[p2]) : 2 + dp[p1 + 1][p2 - 1]
        //            = ELSE : max(dp[p1 + 1][p2], dp[p1][p2 - 1])

        // Base case :
        // if(p1 > p2) return 0 : No need, dp init already has 0
        // if(p1 == p2) return 1 : dp[i][i] = 1

        // So, dp[p1][p2] depends on :
        // - down : dp[p1 + 1][p2]
        // - left : dp[p1][p2 - 1]
        // - diag bottom left : dp[p1 + 1][p2 - 1]

        // So, starting from bottom ...
        // NOTE : We start j from i + 1 because j = i is already 
        // handled by the base case and j < i represents invalid substrings.

        // OR

        // LPS(s) = LCS(s, reverse(s))

        int n = s.length();

        vector<int> cur(n, 0), nxt(n, 0);
        
        // base case for last character
        nxt[n - 1] = 1;

        for(int i = n - 2; i >= 0; i--) {  
            // base case
            cur[i] = 1;
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) {
                    cur[j] = 2 + nxt[j - 1];
                } else {
                    cur[j] = max(nxt[j], cur[j - 1]);
                }
            }
            nxt = cur;
        }

        return nxt[n - 1];

    }
};


class Solution {
public:

    int longestPalindromeSubseq(string s) {
        // p1 = 0 and p2 = n - 1
        // IF s[p1] == s[p2] : go to (p1 + 1, p2 - 1)
        // ELSE : go to (p1 + 1, p2) OR (p1, p2 - 1)

        // dp[p1][p2] means what's the longest palindromic subsequence in 
        // substring s[p1...p2]

        // dp[p1][p2] = IF (s[p1] == s[p2]) : 2 + dp[p1 + 1][p2 - 1]
        //            = ELSE : max(dp[p1 + 1][p2], dp[p1][p2 - 1])

        // Base case :
        // if(p1 > p2) return 0 : No need, dp init already has 0
        // if(p1 == p2) return 1 : dp[i][i] = 1
        
        // NOTE : THESE ARE WRONG as they ignore characters between them.
        // - dp[0][...] = at s[0] and any index p2, what's the LLPS ?
        //              = 2 IF s[0] == s[p2] ELSE 0
        // - dp[...][0] = at any index p1 and s[0], what's the LLPS ?
        //              = 2 IF s[p1] == s[0] ELSE 0

        // So, dp[p1][p2] depends on :
        // - down : dp[p1 + 1][p2]
        // - left : dp[p1][p2 - 1]
        // - diag bottom left : dp[p1 + 1][p2 - 1]

        // So, starting from bottom ...
        // NOTE : We start j from i + 1 because j = i is already 
        // handled by the base case and j < i represents invalid substrings.
        
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) dp[i][i] = 1;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n-1];
    }
};

class Solution {
public:

    int solve(int p1, int p2, const string& s) {
        if(p1 > p2) return 0
        if(p1 == p2) return 1
        if(s[p1] == s[p2]) {
            return 2 + solve(p1 + 1, p2 - 1, s);
        }
        int left = solve(p1 + 1, p2, s);
        int right = solve(p1, p2 - 1, s);
        return max(left, right);
    }

    int longestPalindromeSubseq(string s) {
        // p1 = 0 and p2 = n - 1
        // IF s[p1] == s[p2] : go to (p1 + 1, p2 - 1)
        // ELSE : go to (p1 + 1, p2) OR (p1, p2 - 1)

        int n = s.length();
        if(n == 1) return 1;
        
        return solve(0, n - 1, s);
    }
};