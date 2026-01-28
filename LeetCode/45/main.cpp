class Solution {
public:
  int solve(int ind, int n, vector<int> &arr, vector<int> &dp) {
    if (ind >= n - 1)
      return 0;
    if (arr[ind] == 0)
      return INT_MAX;
    if (dp[ind] != -1)
      return dp[ind];

    int minSteps = INT_MAX;
    int maxSteps = min(n - 1, ind + arr[ind]);

    for (int i = ind + 1; i <= maxSteps; ++i) {
      int steps = solve(i, n, arr, dp);
      if (steps != INT_MAX) {
        minSteps = min(minSteps, 1 + steps);
      }
    }

    dp[ind] = minSteps;
    return minSteps;
  }

  int jump(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, -1);
    return solve(0, n, arr, dp);
  }
};