class Solution {
public:
   
    int maxProfit(vector<int>& arr) {
        int n = arr.size();

        // dp[ind][canBuy] means considering index ind as starting point, what's the 
        // best price I can get

        // So, dp[ind][canBuy] depends on:
        //   - down : dp[ind + 1][canBuy]      (skip)
        //   - diag : dp[ind + 1][!canBuy]     (buy/sell)

        // So, we need to start from the bottom.
        // BASE CASE : 
        //      - dp[n][...] := means at index n, what's the best we can get 
        //                      considering it as the starting index
        //                   := 0 (no ways)
        
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // vector<int> cur(2, 0), nxt(2, 0);
        int curJ = 0, curNotJ = 0, nxtJ = 0, nxtNotJ = 0; 

        for(int i = n - 1; i >= 0; --i) {
            curJ = max(-arr[i] + nxtNotJ, nxtJ);
            curNotJ = max(arr[i] + nxtJ, nxtNotJ);
            nxtJ = curJ;
            nxtNotJ = curNotJ;
        }

        return nxtJ;
    }
};

class Solution {
public:
   
    int maxProfit(vector<int>& arr) {
        int n = arr.size();

        // dp[ind][canBuy] means considering index ind as starting point, what's the 
        // best price I can get

        // dp[ind][canBuy] = IF canBuy : max(
        //                      -arr[i] + dp[ind + 1][!canBuy], dp[ind + 1][canBuy]
        //                   )
        //                   ELSE : max(
        //                      arr[i] + dp[ind + 1][!canBuy], dp[ind + 1][canBuy]
        //                   )
        //                   

        // So, dp[ind][canBuy] depends on:
        //   - down : dp[ind + 1][canBuy]      (skip)
        //   - diag : dp[ind + 1][!canBuy]     (buy/sell)

        // So, we need to start from the bottom.
        // BASE CASE : 
        //      - dp[n][...] := means at index n, what's the best we can get 
        //                      considering it as the starting index
        //                   := 0 (no ways)
        
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        vector<int> cur(2, 0), nxt(2, 0);

        for(int i = n - 1; i >= 0; --i) {
            for(int j = 0; j <= 1; ++j) {
                if(j) {
                    cur[j] = max(-arr[i] + nxt[!j], nxt[j]);
                    // dp[i][j] = max(-arr[i] + dp[i + 1][!j], dp[i + 1][j]);
                } else {
                    cur[j] = max(arr[i] + nxt[!j], nxt[j]);
                    // dp[i][j] = max(arr[i] + dp[i + 1][!j], dp[i + 1][j]);
                }
                nxt = cur;
            }
        }

        return nxt[1];
    }
};  


class Solution {
public:
   
    int maxProfit(vector<int>& arr) {
        int n = arr.size();

        // dp[ind][canBuy] means considering index ind as starting point, what's the 
        // best price I can get

        // dp[ind][canBuy] = IF canBuy : max(
        //                      -arr[i] + dp[ind + 1][!canBuy], dp[ind + 1][canBuy]
        //                   )
        //                   ELSE : max(
        //                      arr[i] + dp[ind + 1][!canBuy], dp[ind + 1][canBuy]
        //                   )
        //                   

        // So, dp[ind][canBuy] depends on:
        //   - down : dp[ind + 1][canBuy]      (skip)
        //   - diag : dp[ind + 1][!canBuy]     (buy/sell)

        // So, we need to start from the bottom.
        // BASE CASE : 
        //      - dp[n][...] := means at index n, what's the best we can get 
        //                      considering it as the starting index
        //                   := 0 (no ways)
        
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int i = n - 1; i >= 0; --i) {
            for(int j = 0; j <= 1; ++j) {
                if(j) {
                    dp[i][j] = max(-arr[i] + dp[i + 1][!j], dp[i + 1][j]);
                } else {
                    dp[i][j] = max(arr[i] + dp[i + 1][!j], dp[i + 1][j]);
                }
            }
        }

        return dp[0][1];
    }
};


class Solution {
public:
    int solve(int ind, bool canBuy, vector<int>& prices) {
        if (ind == prices.size()) return 0;

        if (canBuy) {
            int buy = -prices[ind] + solve(ind + 1, false, prices);
            int skip = solve(ind + 1, true, prices);
            return max(buy, skip);
        } else {
            int sell = prices[ind] + solve(ind + 1, true, prices);
            int skip = solve(ind + 1, false, prices);
            return max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        return solve(0, true, prices);
    }
};