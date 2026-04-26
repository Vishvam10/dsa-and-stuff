class Solution {
public:

    int maximumDetonation(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j) continue;
                int x = arr[j][0] - arr[i][0];
                int y = arr[j][1] - arr[i][1];
                int r = arr[i][2];
                if (1LL * x * x + 1LL * y * y <= 1LL * r * r){
                    adj[i].push_back(j);
                }
            }
        }        
        int ans = 0;
        vector<bool> vis(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            vis.assign(n, false);
            int cnt = 1;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int nei : adj[node]) {
                    if (!vis[nei]){
                        cnt++;
                        q.push(nei);
                        vis[nei] = true;
                    }
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }

};