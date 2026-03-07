class Solution {
public:

    using ull = unsigned long long int;

    int change(int amount, vector<int>& coins) {
        // don't pick (= move ind) and pick (= don't move ind)
        // pick + don't move = pick + don't pick ... so we don't have 3 cases

        // dont = solve(ind + 1, amount - coins[ind])
        // pick = solve(ind, amount - coins[ind]) IF amount >= coins[ind]
        // if amount == 0 => return 1 and ind 0 and n cases => 0

        // dp[ind][amt] means at index "ind", how number of ways
        // can we get "amt" amount
        
        // Base cases : 
        //      - dp[...][0] = number of ways of getting amount 0 using any 
        //      number of indices = 1 (don't pick ... multiple donts is still 1
        //      as the number of ways is 1 ?)
        //      - dp[0][...] = number of ways of getting any amount 
        //        while being on index 0 = 1 IF amount % coins[ind] ELSE 0

        int n = coins.size();
        // vector<vector<ull>> dp(n + 1, vector<ull>(amount + 1, 0));
        
        vector<ull> dp(amount + 1);

        dp[0] = 1;
        for(int i = 0; i <= amount; ++i) dp[i] = (i % coins[0] == 0) ? 1 : 0;
        
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j <= amount; ++j) {
                ull dont = dp[j];
                ull pick = 0;
                if(j >= coins[i]) {
                    pick = dp[j - coins[i]];
                }
                dp[j] = pick + dont;
            }
        }
        return static_cast<int>(dp[amount]);
    }
};


class Solution {
public:

    using ull = unsigned long long int;

    int change(int amount, vector<int>& coins) {
        // don't pick (= move ind) and pick (= don't move ind)
        // pick + don't move = pick + don't pick ... so we don't have 3 cases

        // dont = solve(ind + 1, amount - coins[ind])
        // pick = solve(ind, amount - coins[ind]) IF amount >= coins[ind]
        // if amount == 0 => return 1 and ind 0 and n cases => 0

        // dp[ind][amt] means at index "ind", how number of ways
        // can we get "amt" amount
        
        // Base cases : 
        //      - dp[...][0] = number of ways of getting amount 0 using any 
        //      number of indices = 1 (don't pick ... multiple donts is still 1
        //      as the number of ways is 1 ?)
        //      - dp[0][...] = number of ways of getting any amount 
        //        while being on index 0 = 1 IF amount % coins[ind] ELSE 0

        int n = coins.size();
        // vector<vector<ull>> dp(n + 1, vector<ull>(amount + 1, 0));
        
        vector<ull> prev(amount + 1), cur(amount + 1);

        prev[0] = 1;
        for(int i = 0; i <= amount; ++i) prev[i] = (i % coins[0] == 0) ? 1 : 0;
        
        for(int i = 1; i < n; ++i) {
            cur[0] = 1;
            for(int j = 1; j <= amount; ++j) {
                ull dont = prev[j];
                ull pick = 0;
                if(j >= coins[i]) {
                    pick = cur[j - coins[i]];
                }
                cur[j] = pick + dont;
            }
            prev = cur;
        }
        return static_cast<int>(prev[amount]);
    }
};



class Solution {
public:

    using ull = unsigned long long int;

    int change(int amount, vector<int>& coins) {
        // don't pick (= move ind) and pick (= don't move ind)
        // pick + don't move = pick + don't pick ... so we don't have 3 cases

        // dont = solve(ind + 1, amount - coins[ind])
        // pick = solve(ind, amount - coins[ind]) IF amount >= coins[ind]
        // if amount == 0 => return 1 and ind 0 and n cases => 0

        // dp[ind][amt] means at index "ind", how number of ways
        // can we get "amt" amount
        
        // Base cases : 
        //      - dp[...][0] = number of ways of getting amount 0 using any 
        //      number of indices = 1 (don't pick ... multiple donts is still 1
        //      as the number of ways is 1 ?)
        //      - dp[0][...] = number of ways of getting any amount 
        //        while being on index 0 = 1 IF amount % coins[ind] ELSE 0

        int n = coins.size();
        vector<vector<ull>> dp(n + 1, vector<ull>(amount + 1, 0));

        for(int i = 0; i <= n; ++i) dp[i][0] = 1    ;
        for(int i = 0; i <= amount; ++i) dp[0][i] = (i % coins[0] == 0) ? 1 : 0;
        
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j <= amount; ++j) {
                ull dont = dp[i - 1][j];
                ull pick = 0;
                if(j >= coins[i]) {
                    pick = dp[i][j - coins[i]];
                }
                dp[i][j] = pick + dont;
            }
        }
        return static_cast<int>(dp[n - 1][amount]);
    }
};