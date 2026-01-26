class Solution {
public:

    // Mark as "not changeable"
    void mark(
        int x, int y, int nRows, int nCols, 
        vector<vector<char>>& mat, vector<vector<bool>>& vis
    ) {

        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
        mat[x][y] = 'A';
        vis[x][y] = true;
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if(
                (nx >= 1 && nx < nRows - 1 && ny >= 1 && ny < nCols - 1) &&
                (!vis[nx][ny] && mat[nx][ny] == 'O')
            ) {
                mark(nx, ny, nRows, nCols, mat, vis);
            }
        }
    }

    void solve(vector<vector<char>>& mat) {

        int nRows = mat.size(), nCols = mat[0].size();
        vector<vector<bool>> vis(nRows, vector<bool>(nCols, false));
        
        for(int i = 0; i < nRows; ++i) {
            for(int j = 0; j < nCols; ++j) {
                if(
                    (mat[i][j] == 'O') &&
                    (i == 0 || i == nRows - 1 || j == 0 || j == nCols - 1)
                ) {
                    mark(i, j, nRows, nCols, mat, vis);
                }
            }
        }
        
        for(int i = 0; i < nRows; ++i) {
            for(int j = 0; j < nCols; ++j) {
                if(mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                } else if(mat[i][j] == 'A') {
                    mat[i][j] = 'O';
                }
            }
        }
    }
};