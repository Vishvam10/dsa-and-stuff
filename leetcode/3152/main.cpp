
class Solution {
public:
    vector<bool> isArraySpecial(
        vector<int>& nums, vector<vector<int>>& queries
    ) {
        int n = nums.size();
        vector<bool> ans(queries.size(), false);
        vector<int> pre(n, 0);

        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1];
            pre[i] += (nums[i - 1] % 2 == nums[i] % 2);
        }

        for (int i = 0; i < queries.size(); ++i) {
            int from = queries[i][0];
            int to = queries[i][1];

            ans[i] = (pre[to] - pre[from] == 0);
        }

        return ans;
    }
};
