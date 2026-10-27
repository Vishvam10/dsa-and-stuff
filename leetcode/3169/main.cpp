class Solution {
public:

    using ull = unsigned long long int;

    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    int nRows = 0, nCols = 0;

    ull solve(
        int x, int y, const vector<vector<int>>& mat,
        vector<vector<bool>>& vis
    ) {
        vis[x][y] = true;
        ull sum = mat[x][y];

        for(int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if(
                (nx >= 0 && nx < nRows && ny >= 0 && ny < nCols) &&
                (mat[nx][ny] > 0 && !vis[nx][ny])
            ) {
                sum += solve(nx, ny, mat, vis);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& mat, int k) {
        nRows = mat.size(), nCols = mat[0].size();
        ull ans = 0;
        vector<vector<bool>> vis(nRows, vector<bool>(nCols, false));
        for(int i = 0; i < nRows; ++i) {
            for(int j = 0; j < nCols; ++j) {
                if(mat[i][j] > 0 && !vis[i][j]) {
                    ull sum = solve(i, j, mat, vis);
                    ans += (sum % k == 0);
                }
            }
        }
        return static_cast<int>(ans);
    }
};
