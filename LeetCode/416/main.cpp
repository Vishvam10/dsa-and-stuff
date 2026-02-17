class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2) return false;

        int n = nums.size();
        int target = total / 2;

        vector<bool> prev(target + 1, false), cur(target + 1, false);
        prev[0] = true;

        for (int i = 1; i <= n; ++i) {

            cur[0] = true;

            for (int sum = 1; sum <= target; ++sum) {   

                bool dont = prev[sum];

                bool pick = false;
                if (sum >= nums[i - 1]){
                    pick = prev[sum - nums[i - 1]];
                }

                cur[sum] = pick || dont;
            }

            prev = cur;
        }

        return prev[target];
    }
};

/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(total % 2 == 1) return false;
        if(nums[0] == total / 2) return true;

        // dp[ind][sum] .. we don't need another dimension as that will
        // always be total - sum ? and dp[ind][0] is always true as sum
        // can be 0 if nothing is picked

        // dp[ind + 1][sum] = pick || leave
        //                  = dp[i][sum - nums[i]] || dp[i][sum]
        int target = total / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for(int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }

        for(int i = 1; i <= n; ++i) {
            for(int sum = 1; sum <= target; ++sum) {
                bool dont = dp[i - 1][sum];

                bool pick = false;
                if(sum >= nums[i - 1]) {
                    pick = dp[i - 1][sum - nums[i - 1]];
                }
                
                dp[i][sum] = pick || dont;
            }
        }

        return dp[n][target];
    }
};

class Solution {
public:

    bool solve(
        int ind, int sumA, int sumB, int requiredSum, vector<int>& arr
    ) {

        if(ind == arr.size()) {
            if(sumA == requiredSum || sumB == requiredSum) return true;
            return false;
        }

        if(sumA == requiredSum || sumB == requiredSum) return true;

        bool onA = solve(ind + 1, sumA + arr[ind], sumB, requiredSum, arr);
        bool onB = solve(ind + 1, sumA, sumB + arr[ind], requiredSum, arr);
        return onA || onB;

    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        return solve(0, 0, 0, sum / 2, nums);
    }
};
*/