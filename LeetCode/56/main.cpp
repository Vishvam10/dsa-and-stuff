class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &arr) {
    int n = arr.size();
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());
    ans.emplace_back(arr[0]);

    for (int i = 1; i < n; ++i) {
      vector<int> prev = ans[ans.size() - 1];
      vector<int> cur = arr[i];

      if (cur[0] >= prev[0] && cur[0] <= prev[1]) {
        int low = min(prev[0], cur[0]);
        int high = max(prev[1], cur[1]);
        ans[ans.size() - 1] = {low, high};
      } else {
        ans.emplace_back(arr[i]);
      }
    }

    return ans;
  }
};