class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {

    vector<vector<pair<int, int>>> adj(n + 1);

    for (const auto &x : times) {
      int src = x[0], dest = x[1], wt = x[2];
      adj[src].push_back({dest, wt});
    }

    vector<int> dists(n + 1, INT_MAX);
    dists[k] = 0;

    // (dist, node)
    priority_queue<pair<int, int>> pq;
    pq.push({0, k});

    int ans = -1;

    while (!pq.empty()) {
      auto [dist, node] = pq.top();
      pq.pop();

      for (const auto nei : adj[node]) {
        int nei_node = nei.first, wt = nei.second;
        int new_dist = dist + wt;
        if (new_dist < dists[nei_node]) {
          dists[nei_node] = new_dist;
          pq.push({new_dist, nei_node});
        }
      }
    }

    for (int i = 1; i <= n; ++i) {
      if (dists[i] == INT_MAX) {
        return -1;
      }
      if (dists[i] > 0) {
        ans = max(ans, dists[i]);
      }
    }

    return ans;
  }
};