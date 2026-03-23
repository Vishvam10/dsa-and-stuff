class Solution {
public:
    vector<int> findOrder(int nCourses, vector<vector<int>>& arr) {
        vector<vector<int>> adj(nCourses);
        vector<int> indegrees(nCourses, 0);
        queue<int> q;
        vector<int> ans;
        int cnt = 0;

        for(int i = 0; i < arr.size(); ++i) {
            adj[arr[i][1]].push_back(arr[i][0]);
            indegrees[arr[i][0]]++;
        }

        for(int i = 0; i < nCourses; ++i) {
            if(indegrees[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.emplace_back(node);
            cnt++;
            for(int nei : adj[node]) {
                indegrees[nei]--;
                if(indegrees[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        
        return (cnt == nCourses) ? ans : vector<int>{};
    }
};