class Solution {
public:
  typedef pair<int, pair<int, int>> pp;

  int shortestPathBinaryMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    if (mat[0][0] == 1 || mat[n - 1][n - 1] == 1)
      return -1;

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dist[0][0] = 0;

    // (dist, (x, y))
    priority_queue<pp, vector<pp>, greater<pp>> q;
    q.push({0, {0, 0}});

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (!q.empty()) {

      auto [dis, coord] = q.top();
      auto [x, y] = coord;

      q.pop();

      for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && mat[nx][ny] == 0) {

          int new_dist = 1 + dis;
          if (new_dist < dist[nx][ny]) {
            dist[nx][ny] = new_dist;
            q.push({new_dist, {nx, ny}});
          }
        }
      }
    }

    return dist[n - 1][n - 1] == INT_MAX ? -1 : dist[n - 1][n - 1] + 1;
  }
};