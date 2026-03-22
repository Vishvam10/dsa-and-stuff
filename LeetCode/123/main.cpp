class Solution {
public:

    int maxProfit(vector<int>& arr) {


        // dp[ind][canBuy][transactions] mean for that state, what's the maximum
        // profit we can get

        // dp[ind][canBuy][transactions] depends on :
        //      - dp[ind + 1][0][transactions]
        //      - dp[ind + 1][1][transactions + 1]
        //      - dp[ind + 1][0][transactions]
        //      - dp[ind + 1][1][transactions]

        // So, we will start from bottom. Base case : (already taken care during init)
        //      - dp[...][...][2] == 0
        //      - dp[n - 1][...][...] = 0
        
        int n = arr.size();
        // int dp[n + 1][2][3];
        // memset(dp, 0, sizeof(dp));

        int cur[2][3], nxt[2][3];
        memset(cur, 0, sizeof(cur));
        memset(nxt, 0, sizeof(nxt));

        for(int i = n - 1; i >= 0; --i) {
            for(int j = 0; j <= 1; ++j) {
                for(int k = 0; k < 2; ++k) {
                    // Can buy
                    if(j) {
                        int buy = -arr[i] + nxt[!j][k];
                        int skip = nxt[j][k];
                        cur[j][k] = max(buy, skip);
                    } else {
                        int sell = arr[i] + nxt[!j][k + 1];
                        int skip = nxt[j][k];
                        cur[j][k] = max(sell, skip);
                    }
                }
            }
            memcpy(nxt, cur, sizeof(cur));
        }

        // max({dp[0][1][0], dp[0][1][1], dp[0][1][2]}) is wrong because it means
        // What if I magically started with 1 or 2 transactions already done ?
        // Which is not allowed by problem definition
        return nxt[1][0];

        
    }
};


class Solution {
public:

    int maxProfit(vector<int>& arr) {


        // dp[ind][canBuy][transactions] mean for that state, what's the maximum
        // profit we can get

        // dp[ind][canBuy][transactions] depends on :
        //      - dp[ind + 1][0][transactions]
        //      - dp[ind + 1][1][transactions + 1]
        //      - dp[ind + 1][0][transactions]
        //      - dp[ind + 1][1][transactions]

        // So, we will start from bottom. Base case : (already taken care during init)
        //      - dp[...][...][2] == 0
        //      - dp[n - 1][...][...] = 0
        
        int n = arr.size();
        int dp[n + 1][2][3];
        memset(dp, 0, sizeof(dp));

        for(int i = n - 1; i >= 0; --i) {
            for(int j = 0; j <= 1; ++j) {
                for(int k = 0; k < 2; ++k) {
                    // Can buy
                    if(j) {
                        int buy = -arr[i] + dp[i + 1][!j][k];
                        int skip = dp[i + 1][j][k];
                        dp[i][j][k] = max(buy, skip);
                    } else {
                        int sell = arr[i] + dp[i + 1][!j][k + 1];
                        int skip = dp[i + 1][j][k];
                        dp[i][j][k] = max(sell, skip);
                    }
                }
            }
        }

        // max({dp[0][1][0], dp[0][1][1], dp[0][1][2]}) is wrong because it means
        // What if I magically started with 1 or 2 transactions already done ?
        // Which is not allowed by problem definition
        return dp[0][1][0];

        
    }
};

class Solution {
public:

    int solve(int ind, bool canBuy, int transactions, vector<int>& arr) {
        if(ind >= arr.size()) return 0;
        if(transactions == 2) return 0;

        if(canBuy) {
            int buy = -arr[ind] + solve(ind + 1, false, transactions, arr);
            int skip = solve(ind + 1, true, transactions, arr);
            return max(buy, skip);
        }

        int sell = arr[ind] + solve(ind + 1, true, transactions + 1, arr);
        int skip = solve(ind + 1, false, transactions, arr);
        return max(sell, skip);

    }

    int maxProfit(vector<int>& arr) {
        return solve(0, true, 0, arr);
        
    }
};