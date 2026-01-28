class Solution {
public:
  // Mark as "boundary-reachable"
  void mark(int x, int y, int nRows, int nCols, vector<vector<int>> &mat,
            vector<vector<bool>> &vis) {
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    vis[x][y] = true;
    mat[x][y] = 2;

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];

      if ((nx >= 1 && nx < nRows && ny >= 1 && ny < nCols) &&
          (!vis[nx][ny] && mat[nx][ny] == 1)) {
        mark(nx, ny, nRows, nCols, mat, vis);
      }
    }
  }

  int numEnclaves(vector<vector<int>> &mat) {
    int nRows = mat.size(), nCols = mat[0].size();
    vector<vector<bool>> vis(nRows, vector<bool>(nCols, false));
    int ans = 0;

    for (int i = 0; i < nRows; ++i) {
      for (int j = 0; j < nCols; ++j) {
        if ((i == 0 || i == nRows - 1 || j == 0 || j == nCols - 1) &&
            (mat[i][j] == 1)) {
          mark(i, j, nRows, nCols, mat, vis);
        }
      }
    }

    for (int i = 0; i < nRows; ++i) {
      for (int j = 0; j < nCols; ++j) {
        if (mat[i][j] == 2) {
          mat[i][j] = 1;
        } else if (mat[i][j] == 1) {
          ans++;
        }
      }
    }

    return ans;
  }
};