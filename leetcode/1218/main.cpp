class Solution {
public:
    // int n = 0, d = 0;

    // int solve(int cur, int prev, vector<int>& arr) {
    //     if(cur >= n) return 0;
    //     int pick = 0;
    //     if(prev == -1 || arr[cur] - arr[prev] == d) {
    //         pick = 1 + solve(cur + 1, cur, arr);
    //     }
    //     int dont = solve(cur + 1, prev, arr);
    //     return max(pick, dont);
    // }

    int longestSubsequence(vector<int>& arr, int diff) {
        // n = arr.size(), d = diff;
        // return solve(0, -1, arr);
        unordered_map<int, int> mp;
        int ans = 0;
        for(int x : arr) {
            mp[x] = mp[x - diff] + 1;
            ans = max(ans, mp[x]);
        }
        return ans;
    }
};
