    class Solution {
    public:

        int maxProfit(vector<int>& arr) {

            // dp[ind][canBuy][transactions] mean for that state, what's the maximum
            // profit we can get

            // Unrolling canBuy and transactions :

            // dp[i][1][0] → buy1   (before first buy)
            // dp[i][0][0] → sell1  (after first sell)

            // dp[i][1][1] → buy2   (before second buy)
            // dp[i][0][1] → sell2  (after second sell)

            // dp[i][0][0] = max(dp[i + 1][0][0], price + dp[i+1][1][1])
            // Becomes => sell1 = max(sell1 (of prev iteration), prict + buy2)
            
            // dp[i][1][0] = max(dp[i + 1][1][0], -price + dp[i+1][0][0])
            // Becomes => best1 = max(best1, -price + sell1 (of prev iteration))

            // ... and so on

            int n = arr.size();

            int buy1 = INT_MIN, buy2 = INT_MIN;
            int sell1 = 0, sell2 = 0;

            for (const int& p : arr) {
                buy1  = max(buy1, -p);
                sell1 = max(sell1, buy1 + p);
                buy2  = max(buy2, sell1 - p);
                sell2 = max(sell2, buy2 + p);
            }

            // We used to return nxt[1][0] ... which is buy1 BUT we return sell2 
            // instead as the modeling of problem has changed from "What is the best 
            // outcome from here ?" to "What is the best outcome AFTER each step ?" 
            // So :
            //      - buy1 means intermediate (holding)
            //      - sell1 means realized profit
            //      - buy2 means intermediate
            //      - sell2 means final realized profit

            return sell2;
        }
    };
    
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