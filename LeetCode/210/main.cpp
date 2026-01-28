class Solution {
public:
  vector<int> findOrder(int n, vector<vector<int>> &arr) {
    vector<vector<int>> adj(n);
    vector<int> inDegrees(n);
    vector<int> ans;
    queue<int> q;

    for (const auto &x : arr) {
      adj[x[1]].emplace_back(x[0]);
      inDegrees[x[0]]++;
    }

    for (int i = 0; i < n; ++i) {
      if (inDegrees[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {

      int node = q.front();
      q.pop();
      ans.emplace_back(node);

      for (const auto &nei : adj[node]) {
        inDegrees[nei]--;
        if (inDegrees[nei] == 0) {
          q.push(nei);
        }
      }
    }

    if (ans.size() != n)
      return {};

    return ans;
  }
};