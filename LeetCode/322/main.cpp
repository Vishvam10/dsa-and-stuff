class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        
        // pick (+ dont move) = solve(ind, amount - target)
        // dont (+ move) = solve(ind + 1, amount)
        // pick + move = pick + dont ... so not including that

        // dp[i][j] = min. no. of coins needed to make amount j using coins 0..i
        
        // Base cases : 
        //     - dp[0][...] = min no. of coins needed to get any amount "j" with only 
        //                    first coin
        //                  = j / coins[0] IF j % coins[0] == 0 ELSE INT_MAX
        //     - dp[...][0] = min no. of coins to get amount 0 = 0

        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 0; i < n; ++i) {
            int coin = coins[i];
            for(int j = coin; j <= amount; j++) {
                if(dp[j - coin] != INT_MAX) {
                    dp[j] = min(dp[j], 1 + dp[j - coin]);
                }
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        
        // pick (+ dont move) = solve(ind, amount - target)
        // dont (+ move) = solve(ind + 1, amount)
        // pick + move = pick + dont ... so not including that

        // dp[i][j] = min. no. of coins needed to make amount j using coins 0..i
        
        // Base cases : 
        //     - dp[0][...] = min no. of coins needed to get any amount "j" with only 
        //                    first coin
        //                  = j / coins[0] IF j % coins[0] == 0 ELSE INT_MAX
        //     - dp[...][0] = min no. of coins to get amount 0 = 0

        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));
        vector<int> prev(amount + 1, INT_MAX);
        vector<int> cur(amount + 1, INT_MAX);

        prev[0] = 0;
        
        for(int i = 0; i <= amount; i++) prev[i] = (i % coins[0] == 0) ? i / coins[0] : INT_MAX;

        for(int i = 1; i < n; ++i) {
            cur[0] = 0;
            for(int j = 1; j <= amount; ++j) {
                int dont = prev[j];
                int pick = INT_MAX;
                if(j >= coins[i] && cur[j - coins[i]] != INT_MAX) {
                    pick = 1 + cur[j - coins[i]];
                }
                cur[j] = min(pick, dont);
            }
            prev = cur;
        }
        return (prev[amount] == INT_MAX) ? -1 : prev[amount];
    }
};


class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        
        // pick (+ dont move) = solve(ind, amount - target)
        // dont (+ move) = solve(ind + 1, amount)
        // pick + move = pick + dont ... so not including that

        // dp[i][j] = min. no. of coins needed to make amount j using coins 0..i
        
        // Base cases : 
        //     - dp[0][...] = min no. of coins needed to get any amount "j" with only 
        //                    first coin
        //                  = j / coins[0] IF j % coins[0] == 0 ELSE INT_MAX
        //     - dp[...][0] = min no. of coins to get amount 0 = 0

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));

        for(int i = 0; i < n; ++i) dp[i][0] = 0;
        for(int i = 0; i <= amount; i++) dp[0][i] = (i % coins[0] == 0) ? i / coins[0] : INT_MAX;

        for(int i = 1; i < n; ++i) {
            for(int j = 1; j <= amount; ++j) {
                int dont = dp[i - 1][j];
                int pick = INT_MAX;
                if(j >= coins[i] && dp[i][j - coins[i]] != INT_MAX) {
                    pick = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(pick, dont);
            }
        }
        return (dp[n - 1][amount] == INT_MAX) ? -1 : dp[n - 1][amount];
    }
};