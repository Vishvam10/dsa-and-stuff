class Solution {
public:

    int dijk(int src, int n, vector<vector<pair<int,int>>>& adj) {
        
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dists(n, INT_MAX);
        dists[src] = 0;

        pq.push({0, src});

        while(!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            if(dist > dists[node]) continue;

            for(const auto& nei : adj[node]) {
                auto [nei_node, wt] = nei;
                int new_dist = dist + wt;

                if(new_dist < dists[nei_node]) {
                    dists[nei_node] = new_dist;
                    pq.push({new_dist, nei_node});
                }
            }
        }

        return dists[n - 1];
    }

    int minimumObstacles(vector<vector<int>>& mat) {
        int nRows = mat.size();
        int nCols = mat[0].size();
        int n = nRows * nCols;

        vector<vector<pair<int,int>>> adj(n);

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};

        for(int i = 0; i < nRows; ++i) {
            for(int j = 0; j < nCols; ++j) {

                int node = i * nCols + j;

                for(int k = 0; k < 4; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx >= 0 && nx < nRows &&
                       ny >= 0 && ny < nCols) {

                        int nei_node = nx * nCols + ny;
                        int wt = mat[nx][ny];

                        adj[node].push_back({nei_node, wt});
                    }
                }
            }
        }

        return dijk(0, n, adj);
    }
};