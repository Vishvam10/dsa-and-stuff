class Solution {
public:

    // (dist, node, consecutive count)
    using State = tuple<int, int, int>;

    int shortestPath(
        int n, vector<vector<int>>& edges,
        string labels, int k
    ) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});

        vector<vector<int>> dists(n, vector<int>(k + 1, INT_MAX));
        dists[0][1] = 0;

        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [dist, node, cnt] = pq.top();
            pq.pop();

            if (dist != dists[node][cnt]) continue;

            for (auto [nei, w] : adj[node]) {
                int newCnt = (labels[nei] == labels[node]) ? cnt + 1 : 1;
                if (newCnt > k) continue;

                int newDist = dist + w;
                if (newDist < dists[nei][newCnt]) {
                    dists[nei][newCnt] = newDist;
                    pq.push({newDist, nei, newCnt});
                }
            }
        }

        int ans = *min_element(dists[n - 1].begin(), dists[n - 1].end());
        return ans == INT_MAX ? -1 : ans;
    }
};
