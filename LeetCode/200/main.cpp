class Solution {
public:
  int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

  void bfs(int x, int y, int nRows, int nCols, vector<vector<char>> &mat,
           vector<vector<bool>> &vis) {

    vis[x][y] = true;

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if ((nx >= 0 && nx < nRows && ny >= 0 && ny < nCols) &&
          mat[nx][ny] == '1' && !vis[nx][ny]) {
        bfs(nx, ny, nRows, nCols, mat, vis);
      }
    }
  }

  int numIslands(vector<vector<char>> &mat) {

    int nRows = mat.size(), nCols = mat[0].size();
    int ans = 0;
    vector<pair<int, int>> arr;
    vector<vector<bool>> vis(nRows, vector<bool>(nCols, false));

    for (int i = 0; i < nRows; ++i) {
      for (int j = 0; j < nCols; ++j) {
        if (mat[i][j] == '1') {
          arr.push_back({i, j});
        }
      }
    }

    for (int i = 0; i < arr.size(); ++i) {
      auto [x, y] = arr[i];
      if (!vis[x][y]) {
        bfs(x, y, nRows, nCols, mat, vis);
        ans++;
      }
    }

    return ans;
  }
};