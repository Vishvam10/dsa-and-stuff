class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // dp[ind][prev+1] represents the length of the longest
        // increasing subsequence (LIS) starting from index 'ind', where
        // prev is the index of the previous element included in the
        // subsequence. We use prev + 1 in the DP table to handle prev =
        // -1 (no previous element).

        // Base cases :
        //      - dp[0][...] = len(LIS) using only 0th index = 0
        //      - dp[...][0] = len(LIS) using any index BUT prev is 0
        //                    (nothing) = 1

        // dp[ind][prev] depends on :
        //      - left : dp[ind - 1][prev]
        //      - jump  : dp[ind - 1][ind]

        // The jump can make ind > prev so, it's better to start from
        // the bottom

        int n = nums.size();
        vector<int> dp(n + 1, 0);

        for (int ind = n - 1; ind >= 0; --ind) {
            for (int prev = ind - 1; prev >= -1; --prev) {
                int dont = dp[prev + 1];
                int take = 0;
                if(prev == -1 || nums[ind] > nums[prev]) {
                    take = 1 + dp[ind + 1];
                }
                dp[prev + 1] = max(take, dont);
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // dp[ind][prev+1] represents the length of the longest
        // increasing subsequence (LIS) starting from index 'ind', where
        // prev is the index of the previous element included in the
        // subsequence. We use prev + 1 in the DP table to handle prev =
        // -1 (no previous element).

        // Base cases :
        //      - dp[0][...] = len(LIS) using only 0th index = 0
        //      - dp[...][0] = len(LIS) using any index BUT prev is 0
        //                    (nothing) = 1

        // dp[ind][prev] depends on :
        //      - left : dp[ind - 1][prev]
        //      - jump  : dp[ind - 1][ind]

        // The jump can make ind > prev so, it's better to start from
        // the bottom

        int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> nxt(n + 1, 0);  // dp[ind + 1][*]
        vector<int> cur(n + 1, 0);  // dp[ind][*]

        for (int ind = n - 1; ind >= 0; --ind) {
            for (int prev = ind - 1; prev >= -1; --prev) {
                int dont = nxt[prev + 1];
                int take = 0;
                if(prev == -1 || nums[ind] > nums[prev]) {
                    take = 1 + nxt[ind + 1];
                }
                cur[prev + 1] = max(take, dont);
            }
            // nxt = cur; Instead of this, we do a pointer swap :
            // (we don't need cur anyway as it'll be reset)
            swap(nxt, cur);
        }
        return nxt[0];
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // dp[ind][prev+1] represents the length of the longest
        // increasing subsequence (LIS) starting from index 'ind', where
        // prev is the index of the previous element included in the
        // subsequence. We use prev + 1 in the DP table to handle prev =
        // -1 (no previous element).

        // Base cases :
        //      - dp[0][...] = len(LIS) using only 0th index = 0
        //      - dp[...][0] = len(LIS) using any index BUT prev is 0
        //                    (nothing) = 1

        // dp[ind][prev] depends on :
        //      - left : dp[ind - 1][prev]
        //      - jump  : dp[ind - 1][ind]

        // The jump can make ind > prev so, it's better to start from
        // the bottom

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < n; ++i)
            dp[i][0] = 1;

        for (int ind = n - 1; ind >= 0; --ind) {
            for (int prev = ind - 1; prev >= -1; --prev) {
                int dont = dp[ind + 1][prev + 1];
                int take = (prev == -1 || nums[ind] > nums[prev])
                               ? 1 + dp[ind + 1][ind + 1]
                               : 0;
                dp[ind][prev + 1] = max(take, dont);
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int solve(int ind, int prevInd, vector<int>& arr) {
        if (ind == arr.size())
            return 0;

        int take = 0;
        if (prevInd == -1 || arr[ind] > arr[prevInd]) {
            take = 1 + solve(ind + 1, ind, arr);
        }

        int dont = solve(ind + 1, prevInd, arr);

        return max(take, dont);
    }

    int lengthOfLIS(vector<int>& nums) { 
        return solve(0, -1, nums);
    }
};