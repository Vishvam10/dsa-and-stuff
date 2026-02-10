class Solution {
public:
  int orangesRotting(vector<vector<int>> &mat) {
    int nRows = mat.size(), nCols = mat[0].size();
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int ans = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < nRows; ++i) {
      for (int j = 0; j < nCols; ++j) {
        if (mat[i][j] == 2) {
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {

      bool updated = false;
      int n = q.size();

      for (int i = 0; i < n; ++i) {

        auto [x, y] = q.front();
        q.pop();

        for (int j = 0; j < 4; j++) {
          int nx = x + dx[j], ny = y + dy[j];
          if ((nx >= 0 && nx < nRows && ny >= 0 && ny < nCols) &&
              mat[nx][ny] == 1) {
            mat[nx][ny] = 2;
            q.push({nx, ny});
            updated = true;
          }
        }
      }
      ans += (updated == true);
    };

    for (int i = 0; i < nRows; ++i) {
      for (int j = 0; j < nCols; ++j) {
        if (mat[i][j] == 1) {
          return -1;
        }
      }
    }

    return ans;
  }
};