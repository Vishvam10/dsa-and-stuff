class Solution {
public:

    int findCheapestPrice(
        int n, vector<vector<int>>& fl, int src, int dst, int k
    ) {
        // {node, wt}
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& node : fl) {
            adj[node[0]].push_back({node[1], node[2]});
        }
        
        vector<int> dists(n, INT_MAX);
        
        // {stops, dist, node}
        queue<tuple<int,int,int>> q;

        q.push({0, 0, src});
        dists[src] = 0;

        while (!q.empty()) {
            auto [stops, dist, node] = q.front();
            q.pop();

            if (stops > k) continue;

            for (const auto& [nei, wt] : adj[node]) {
                int newDist = dist + wt;

                if (newDist < dists[nei]) {
                    dists[nei] = newDist;
                    q.push({stops + 1, newDist, nei});
                }
            }
        }

        return dists[dst] == INT_MAX ? -1 : dists[dst];
    }
};