class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        for (int i = 0; i < (1 << n); ++i) {
            int res = 0;
            for (int j = 0; j < n; ++j) if (i & (1 << j)) res ^= arr[j];
            ans += res;
        }
        return ans;
    }
};
