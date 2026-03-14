class Solution {
public:

    int longestCommonSubsequence(string a, string b) {
        // If a[p1] == b[p2], then move both
        // If a[p1] != b[p2], then, move p1 OR move p2

        // dp[p1][p2] means :
        // len of LCS of first i chars of a, first j chars of b

        // dp[p1][p2] = IF a[p1] == b[p2], 1 + dp[p1 - 1][p2 - 1]
        //              ELSE, max(dp[p1 - 1][p2], dp[p1][p2 - 1])

        // dp[i][j] depends on :
        // - left : dp[i - 1][j]
        // - up : dp[i][j - 1]
        // - diag left up : dp[i - 1][j - 1]

        // So we only need : previous row and current row

        int nRows = a.length(), nCols = b.length();

        vector<int> prev(nCols + 1, 0), cur(nCols + 1, 0);

        for(int i = 1; i <= nRows; ++i) {
            for(int j = 1; j <= nCols; ++j) {
                if(a[i - 1] == b[j - 1]) {
                    cur[j] = 1 + prev[j - 1];
                } else {
                    cur[j] = max(prev[j], cur[j - 1]);
                }
            }
            prev = cur;
        }

        return prev[nCols];

    }
};


class Solution {
public:

    int longestCommonSubsequence(string a, string b) {
        // If a[p1] == b[p2], then move both
        // If a[p1] != b[p2], then, move p1 OR move p2

        // dp[p1][p2] means :
        // len of LCS of first i chars of a, first j chars of b

        // dp[p1][p2] = IF a[p1] == b[p2], 1 + dp[p1 - 1][p2 - 1]
        //              ELSE, max(dp[p1 - 1][p2], dp[p1][p2 - 1])

        // Base cases : 
        // - dp[0][...] = For (0, any index p2), what's the len(LCS(a, b))
        //              = max(dp[0][p2 - 1], (a[0] == b[j]))
        // - dp[...][0] = For (any index p1, 0), what's the len(LCS(a, b))
        //              = max(dp[p1 - 1][0], (a[0] == b[j]))
        // 
        // In the base case, we need to propagate the LCS forward. Eg :
        // a = "ab", b = "aaab", row 0 should be [1, 1, 1, 1]
        // If we just did 1 IF (a[0] == b[j] or vice versa) ELSE 0, 
        // we will get [1, 1, 1, 0]
        // 
        // BUT, the recurrence relation ALREADY TAKES CARE OF MAX()
        // So, we just start from (1, 1) to (nRows + 1, nCols + 1) and
        // instead we check for a[i - 1] == b[i - 1]

        // Since, we are starting from 1 now, index 0 just means empty 
        // strings and base case is already take care as dp[0][...] and
        // dp[...][0] = 0

        int nRows = a.length(), nCols = b.length();

        vector<vector<int>> dp(nRows + 1, vector<int>(nCols + 1, 0));

        for(int i = 1; i <= nRows; ++i) {
            for(int j = 1; j <= nCols; ++j) {
                if(a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[nRows][nCols];

    }
};


class Solution {
public:

    int solve(int p1, int p2, string a, string b) {
        if(p1 >= a.length() || p2 >= b.length()) {
            return 0;
        }

        if(a[p1] == b[p2]) {
            return 1 + solve(p1 + 1, p2 + 1, a, b);
        }

        int pick = solve(p1 + 1, p2, a, b);
        int dont = solve(p1, p2 + 1, a, b);
        return max(pick, dont);

    }

    int longestCommonSubsequence(string a, string b) {
        // If a[p1] == b[p2], then move both
        // If a[p1] != b[p2], then, move p1 OR move p2


        return solve(0, 0, text1, text2);

    }
};