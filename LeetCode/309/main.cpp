class Solution {
public:

    int maxProfit(vector<int>& arr) {

        // dp[ind][purchaseState] means at that index, what's the max profit we can get

        // dp[i][j] depends on :
        //      - dp[i + 1][0]
        //      - dp[i + 1][1]
        //      - dp[i + 1][2]

        // So, we will start from bottom. Base cases : (already taken care during init)
        //      - dp[n][...] = 0

        int n = arr.size();
        // vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        int cur[3], nxt[3];
        memset(cur, 0, sizeof(cur));
        memset(nxt, 0, sizeof(nxt));

        for(int i = n - 1; i >= 0; --i) {
            
            // Can buy now
            cur[0] = max(-arr[i] + nxt[2], nxt[0]);

            // Cooldown only
            cur[1] = nxt[0];

            // Sell only
            cur[2] = max(arr[i] + nxt[1], nxt[2]);

            // nxt = cur;
            memcpy(nxt, cur, sizeof(cur));
        }

        return nxt[0];

    }
};

class Solution {
public:

    int maxProfit(vector<int>& arr) {

        // dp[ind][purchaseState] means at that index, what's the max profit we can get

        // dp[i][j] depends on :
        //      - dp[i + 1][0]
        //      - dp[i + 1][1]
        //      - dp[i + 1][2]

        // So, we will start from bottom. Base cases : (already taken care during init)
        //      - dp[n][...] = 0

        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        for(int i = n - 1; i >= 0; --i) {
            
            // Can buy now
            dp[i][0] = max(
                -arr[i] + dp[i + 1][2],
                dp[i + 1][0]
            );

            // Cooldown only
            dp[i][1] = dp[i + 1][0];

            // Sell only
            dp[i][2] = max(
                arr[i] + dp[i + 1][1],
                dp[i + 1][2]
            );
        }
        return dp[0][0];

    }
};

class Solution {
public:

    int maxProfit(vector<int>& arr) {

        // dp[ind][purchaseState] means at that index, what's the max profit we can get

        // dp[i][j] depends on :
        //      - dp[i + 1][0]
        //      - dp[i + 1][1]
        //      - dp[i + 1][2]

        // So, we will start from bottom. Base cases : (already taken care during init)
        //      - dp[n][...] = 0

        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        for(int i = n - 1; i >= 0; --i) {
            for(int j = 0; j < 3; ++j) {
                if(j == 0) { 
                    // Can buy now
                    int buy = -arr[i] + dp[i + 1][2];
                    int skip = dp[i + 1][0];
                    dp[i][j] = max(buy, skip);
                }
                else if(j == 1) { 
                    // Cooldown only
                    dp[i][j] = dp[i + 1][0];
                }
                else { 
                    // Sell only
                    int sell = arr[i] + dp[i + 1][1];
                    int skip = dp[i + 1][2];
                    dp[i][j] = max(sell, skip);
                }
            }
        }
        return dp[0][0];

    }
};

class Solution {
public:

    int solve(int ind, int purchaseState, vector<int>& arr) {
        if(ind >= arr.size()) return 0;

        // Can buy now
        if(purchaseState == 0) {
            int buy = -arr[ind] + solve(ind + 1, 2, arr);
            int skip = solve(ind + 1, 0, arr);
            return max(buy, skip);
        }

        // Cooldown only
        if(purchaseState == 1) {
            int skipButBuyNext = solve(ind + 1, 0, arr);
            return skipButBuyNext;
        }

        // Sell only
        // if(purchaseState == 2)

        int sell = arr[ind] + solve(ind + 1, 1, arr);
        int skip = solve(ind + 1, 2, arr);
        return max(sell, skip);
    }

    int maxProfit(vector<int>& arr) {
        return solve(0, 0, arr);
    }
};