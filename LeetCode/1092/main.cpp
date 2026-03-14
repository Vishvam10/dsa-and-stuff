class Solution {
public:

    string shortestCommonSupersequence(string a, string b) {
        // Worst case scenario, just concat them : c = a + b
        // So, in c, we now have redundant characters .. we need to remove
        // a few. We can remove common characters from them BUT we need
        // to presere the order of common characters => we need to remove 
        // longest common subsequence

        // Construct c as LCS(a, b) + remaining A + remaining B

        // dp[i][j] = IF a[i - 1] == b[j - 1] : 2 + solve(i + 1, j + 1)
        //            ELSE : max(solve(i + 1, j), solve(i, j + 1)
        // Base case : dp[0][...] = 0 and dp[...][0] = 0 as 
        // a[0] and b[0] are empty strings

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

        string ans = "";
        int i = nRows, j = nCols;
        while(i > 0 && j > 0) {
            // Same, so include once
            if(a[i - 1] == b[j - 1]) {
                ans += a[i - 1];
                i--; j--;
            }
            // Move towards the greatest value 
            else if(dp[i][j - 1] > dp[i - 1][j]) {
                ans += b[j - 1];
                j--;
            } else {
                ans += a[i - 1];
                i--;
            }
        }

        // Add the remaining chars
        while(i > 0) {
            ans += a[i - 1];
            i--;
        }

        while(j > 0) {
            ans += b[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};