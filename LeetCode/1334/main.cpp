class Solution {
public:

    int dijkWithThreshold(
        int src, int thresh, int n,
        vector<vector<pair<int, int>>>& adj
    ) {
        int ans = 0;
        vector<int> dists(n, INT_MAX);
        dists[src] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        pq.push({0, src});

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            for (auto [to, wt] : adj[node]) {
                int new_dist = dist + wt;

                if (new_dist < dists[to]) {
                    dists[to] = new_dist;
                    pq.push({new_dist, to});
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (i != src && dists[i] <= thresh)
                ans++;
        }

        return ans;
    }


    int findTheCity(int n, vector<vector<int>>& edges, int thresh) {
        vector<vector<pair<int, int>>> adj(n);
        int minCities = INT_MAX, ans = 0;

        for(const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        for(int i = 0; i < n; ++i) {
            int numCities = dijkWithThreshold(i, thresh, n, adj);
            if(numCities <= minCities) {
                minCities = numCities;
                ans = i;
            }
        }
        return ans;
    }
};