class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<vector<int>> adj(n);
        vector<int> inDegrees(n);
        queue<int> q;
        int count = 0;

        for (const auto& ele : arr) {
            adj[ele[1]].push_back(ele[0]);
            inDegrees[ele[0]]++;
        }

        for (int i = 0; i < n; i++) {
            if(inDegrees[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for(const auto nei : adj[node]) {
                inDegrees[nei]--;
                if(inDegrees[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return count == n;
    }
};