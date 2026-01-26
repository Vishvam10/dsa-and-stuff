class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int nRows = mat.size(), nCols = mat[0].size();
        vector<vector<int>> ans(nRows, vector<int>(nCols, 0));
        vector<vector<bool>> vis(nRows, vector<bool>(nCols, false));

        queue<pair<pair<int, int>, int>> q;
        
        for(int i = 0; i < nRows; ++i) {
            for(int j = 0; j < nCols; ++j) {
                if(mat[i][j] == 0) {
                    vis[i][j] = true;
                    q.push({{i, j}, 0});
                }
            }   
        }

        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

        while(!q.empty()) {
            auto [cell, dis] = q.front();
            int x = cell.first;
            int y = cell.second;

            q.pop();
	        ans[x][y] = dis; 

            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if(
                    nx >= 0 && nx < nRows && ny >= 0 && ny < nCols &&
                    !vis[nx][ny]
                ) {
                    vis[nx][ny] = true;
                    q.push({{nx, ny}, dis + 1});
                }
            }
        }

        return ans;

    }
};