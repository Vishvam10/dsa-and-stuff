class Solution {
public:
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int nRows = 0, nCols = 0;

    int solve(
        int x, int y, const vector<vector<int>>& mat,
        vector<vector<bool>>& vis
    ) {
        vis[x][y] = true;
        int ans = mat[x][y];
        for(int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if(
                (nx >= 0 && nx < nRows && ny >= 0 && ny < nCols) &&
                (mat[nx][ny] != 0 && !vis[nx][ny])
            ) {
                ans += solve(nx, ny, mat, vis);
            }
        }
        return ans;
    }

    int findMaxFish(vector<vector<int>>& mat) {
        nRows = mat.size(), nCols = mat[0].size();
        vector<vector<bool>> vis(nRows, vector<bool>(nCols, false));
        int ans = INT_MIN;
        for(int i = 0; i < nRows; ++i) {
            for(int j = 0; j < nCols; ++j) {
                if(mat[i][j] != 0 && !vis[i][j]) {
                    ans = max(ans, solve(i, j, mat, vis));
                }
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};
