class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n == 1) return 0;

        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int prevEnd = arr[0][1];
        vector<int> cur;
        int ans = 0;

        for(int i = 1; i < n; ++i) {
            cur = arr[i];
            if(cur[0] < prevEnd) {
                ans++;
            } else {
                prevEnd = cur[1];
            }
        }

        return ans;
        
    }
};