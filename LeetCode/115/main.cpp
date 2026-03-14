class Solution {
public:

    using ull = unsigned long long int;

    int numDistinct(string a, string b) {
        if(a == b) return 1;
       
        // dp[p1][p2] = ways to form b[0..j-1] using a[0..i-1]
        //            = IF a[p1] == b[p2] : dp[p1 - 1][p2 - 1] + dp[p1 - 1][p2]
        //              ELSE : dp[p1 - 1][p2]

        // So, dp[p1][p2] depends on :
        //      - left : dp[p1 - 1][p2]
        //      - diag top left : dp[p1 - 1][p2 - 1]

        // With 1D compression:
        // dp[j] represents dp[i-1][j] (previous row)
        // dp[j-1] represents dp[i-1][j-1]
        // We iterate j from right -> left so that dp[j-1] is not overwritten.

        // Base cases :
        //      - dp[...][0] = 1 (as 0 means empty string and number of ways 
        //                        to form an empty string using any number 
        //                        chars = 1)

        int nRows = a.length(), nCols = b.length();

        vector<ull> dp(nCols + 1, 0);

        // dp[0][0] = 1
        dp[0] = 1;

        for(int i = 1; i <= nRows; ++i) {
            // iterate backwards to preserve previous-row values
            for(int j = nCols; j >= 1; --j) {

                if(a[i - 1] == b[j - 1]) {
                    // dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
                    dp[j] = dp[j - 1] + dp[j];
                }
                // ELSE : dp[i - 1][j] (already stored in dp[j])
            }
        }

        return static_cast<int>(dp[nCols]);
    }
};

class Solution {
public:

    using ull = unsigned long long int;

    int numDistinct(string a, string b) {
        if (a.length() < b.length()) return 0;
        if(a == b) return 1;
       
        // dp[p1][p2] = ways to form b[0..j-1] using a[0..i-1]
        //            = IF a[p1] == b[p2] : dp[p1 - 1][p2 - 1] + dp[p1 - 1][p2]
        //              ELSE : dp[p1 - 1][p2]

        // So, dp[p1][p2] depends on :
        //      - left : dp[p1 - 1][p2]
        //      - diag top left : dp[p1 - 1][p2 - 1]

        // So, we will start from top left corner

        // Base cases :
        //      - dp[...][0] = 1 (as 0 means empty string and number of ways 
        //                        to form an empty string using any number 
        //                        chars = 1)

        int nRows = a.length(), nCols = b.length();

        // vector<vector<ull>> dp(nRows + 1, vector<ull>(nCols + 1, 0));
        vector<ull> prev(nCols + 1, 0), cur(nCols + 1, 0);
        
        // for(int i = 0; i <= nRows; ++i) dp[i][0] = 1;
        prev[0] = 1;

        for(int i = 1; i <= nRows; ++i) {
            cur[0] = 1;
            for(int j = 1; j <= nCols; ++j) {
                if(a[i - 1] == b[j - 1]) {
                    // dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    cur[j] = prev[j - 1] + prev[j];
                } else {
                    // dp[i][j] = dp[i - 1][j];
                    cur[j] = prev[j];
                }
            }
            prev = cur;
        }

        // return static_cast<int>(dp[nRows][nCols]);
        return static_cast<int>(prev[nCols]);

    }
};


class Solution {
public:

    using ull = unsigned long long int;

    int numDistinct(string a, string b) {
        if(a == b) return 1;
        // p1 = 0 and p2 = 0
        // IF a[p1] == b[p2] : 
        //      - Either choose from a and move both : p1 + 1, p2 + 1
        //      - Ignore current match and move p1 : p1 + 1, p2
        // ELSE : p1 + 1

        // dp[p1][p2] = ways to form b[0..j-1] using a[0..i-1]
        //            = IF a[p1] == b[p2] : dp[p1 - 1][p2 - 1] + dp[p1 - 1][p2]
        //              ELSE : dp[p1 - 1][p2]

        // So, dp[p1][p2] depends on :
        //      - left : dp[p1 - 1][p2]
        //      - diag top left : dp[p1 - 1][p2 - 1]

        // So, we will start from top left corner

        // Base cases :
        //      - dp[...][0] = 1 (as 0 means empty string and number of ways 
        //                        to form an empty string using any number 
        //                        chars = 1)

        int nRows = a.length(), nCols = b.length();
        vector<vector<ull>> dp(nRows + 1, vector<ull>(nCols + 1, 0));

        for(int i = 0; i <= nRows; ++i) dp[i][0] = 1;

        for(int i = 1; i <= nRows; ++i) {
            for(int j = 1; j <= nCols; ++j) {
                if(a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return static_cast<int>(dp[nRows][nCols]);
    }
};

class Solution {
public:

    int solve(int p1, int p2, const string& a, const string& b) {
        if (p2 == b.length()) return 1;
        if (p1 == a.length()) return 0;

        if (a[p1] == b[p2]) {
            int pick = solve(p1 + 1, p2 + 1, a, b);
            int dont = solve(p1 + 1, p2, a, b);
            return pick + dont;
        }

        return solve(p1 + 1, p2, a, b);
    }

    int numDistinct(string a, string b) {
        // p1 = 0 and p2 = 0
        // IF a[p1] == b[p2] : 
        //      - Either choose from a and move both : p1 + 1, p2 + 1
        //      - Ignore current match and move p1 : p1 + 1, p2
        // ELSE : p1 + 1
        return solve(0, 0, a, b);
    }
};