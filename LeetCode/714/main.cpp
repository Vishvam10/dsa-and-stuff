class Solution {
public:


    int maxProfit(vector<int>& arr, int fee) {

        // dp[ind][canBuy] means at that state what's the max profit we can make

        // dp[i][j] depends on :
        //      - dp[i + 1][0]
        //      - dp[i + 1][1]

        // So, we start from the bottom. Base cases : (already taken care during init)
        //      - dp[n][...] = 0

        int n = arr.size();
        int nxt1 = 0, nxt2 = 0;

        for(int i = n - 1; i >= 0; --i) {
            int cur1 = max(-arr[i] + nxt2, nxt1);
            int cur2 = max(arr[i] - fee + nxt1, nxt2);

            nxt1 = cur1;
            nxt2 = cur2;
        }


        return nxt1;
    }
};


class Solution {
public:


    int maxProfit(vector<int>& arr, int fee) {

        // dp[ind][canBuy] means at that state what's the max profit we can make

        // dp[i][j] depends on :
        //      - dp[i + 1][0]
        //      - dp[i + 1][1]

        // So, we start from the bottom. Base cases : (already taken care during init)
        //      - dp[n][...] = 0

        int n = arr.size();
        int cur[2], nxt[2];
        memset(cur, 0, sizeof(cur));
        memset(nxt, 0, sizeof(nxt));

        for(int i = n - 1; i >= 0; --i) {
            for(int j = 0; j < 2; ++j) {
                // Can buy
                if (j) {
                    int buy = -arr[i] + nxt[!j];
                    int skip = nxt[j];
                    cur[j] = max(buy, skip);
                } else {
                    int sell = arr[i] - fee + nxt[!j];
                    int skip = nxt[j];
                    cur[j] = max(sell, skip);
                }
            }
            memcpy(nxt, cur, sizeof(cur));
        }


        return nxt[1];
    }
};

class Solution {
public:


    int maxProfit(vector<int>& arr, int fee) {

        // dp[ind][canBuy] means at that state what's the max profit we can make

        // dp[i][j] depends on :
        //      - dp[i + 1][0]
        //      - dp[i + 1][1]

        // So, we start from the bottom. Base cases : (already taken care during init)
        //      - dp[n][...] = 0

        int n = arr.size();
        int dp[n + 1][2];
        memset(dp, 0, sizeof(dp));

        for(int i = n - 1; i >= 0; --i) {
            for(int j = 0; j < 2; ++j) {
                // Can buy
                if (j) {
                    int buy = -arr[i] + dp[i + 1][!j];
                    int skip = dp[i + 1][j];
                    dp[i][j] = max(buy, skip);
                } else {
                    int sell = arr[i] - fee + dp[i + 1][!j];
                    int skip = dp[i + 1][j];
                    dp[i][j] = max(sell, skip);
                }
            }
        }


        return dp[0][1];
    }
};

class Solution {
public:

    int solve(int ind, bool canBuy, int fee, vector<int>& arr) {
        if(ind >= arr.size()) return 0;

        if(canBuy) {
            int buy = -arr[ind] + solve(ind + 1, false, fee, arr);
            int skip = solve(ind + 1, true, fee, arr);
            return max(buy, skip);
        }

        int sell = arr[ind] - fee + solve(ind + 1, true, fee, arr);
        int skip = solve(ind + 1, false, fee, arr);
        return max(sell, skip);
    }

    int maxProfit(vector<int>& arr, int fee) {
        return solve(0, true, fee, arr);
    }
};