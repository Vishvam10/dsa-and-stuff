class Solution {
public:
    bool carPooling(vector<vector<int>>& arr, int cap) {
        vector<int> ts(1001);
        for (auto x : arr) ts[x[1]] += x[0], ts[x[2]] -= x[0];
        for (auto i = 0; cap >= 0 && i < 1001; ++i) cap -= ts[i];
        return cap >= 0;
    }
};
