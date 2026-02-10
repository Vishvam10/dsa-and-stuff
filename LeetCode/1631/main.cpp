class Solution {
public:
  // (diff, (x, y))
  typedef pair<int, pair<int, int>> pp;

  int minimumEffortPath(vector<vector<int>> &mat) {
    int nRows = mat.size(), nCols = mat[0].size();

    vector<vector<int>> efforts(nRows, vector<int>(nCols, INT_MAX));
    efforts[0][0] = 0;

    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push({0, {0, 0}});

    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

    while (!pq.empty()) {

      auto [eff, coords] = pq.top();
      auto [x, y] = coords;

      pq.pop();

      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx > nRows - 1 || ny < 0 || ny > nCols - 1) {
          continue;
        }

        int effort = max(eff, abs(mat[x][y] - mat[nx][ny]));

        if (effort < efforts[nx][ny]) {
          efforts[nx][ny] = effort;
          pq.push({effort, {nx, ny}});
        }
      }
    }

    int ans = efforts[nRows - 1][nCols - 1];
    return ans == INT_MAX ? -1 : ans;
  }
};