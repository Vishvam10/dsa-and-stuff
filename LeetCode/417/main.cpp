class Solution {
public:
    int nRows = 0, nCols = 0;

    void dfs(
        int x, int y, vector<vector<int>>& mat, 
        vector<vector<bool>>& vis
    ) {
        vis[x][y] = true;

        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(
                (nx >= 0 && nx < nRows && ny >= 0 && ny < nCols) &&
                (!vis[nx][ny] && mat[nx][ny] >= mat[x][y])
            ) {
                dfs(nx,ny,mat,vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {

        nRows = mat.size(), nCols = mat[0].size();

        vector<vector<bool>> pac(nRows, vector<bool>(nCols, false));
        vector<vector<bool>> atl(nRows, vector<bool>(nCols, false));

        // Pacific
        for(int i = 0; i < nRows; ++i) dfs(i,  0, mat, pac);
        for(int j = 0; j < nCols; ++j) dfs(0, j, mat, pac);

        // Atlantic
        for(int i = 0; i < nRows; ++i) dfs(i, nCols - 1, mat, atl);
        for(int j = 0; j < nCols; ++j) dfs(nRows - 1, j, mat, atl);

        vector<vector<int>> res;

        for(int i = 0; i < nRows; ++i){
            for(int j = 0; j < nCols; ++j){
                if(pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};