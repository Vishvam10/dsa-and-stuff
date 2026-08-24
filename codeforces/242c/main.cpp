#include <cassert>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;
using ull = unsigned long long;

ull encode(int x, int y) {
	return (static_cast<ull>(x) << 32) | static_cast<unsigned int>(y);
}

void solve() {
	int x0, y0, x1, y1;
	cin >> x0 >> y0 >> x1 >> y1;

	int n;
	cin >> n;

	unordered_set<ull> allowed;

	// Total length of all segments <= 1e5, so, expanding them
	// into individual cells is fine ? ... No need of merging ?
	for (int i = 0; i < n; ++i) {
		int row, l, r;
		cin >> row >> l >> r;
		for (int col = l; col <= r; ++col) {
			allowed.insert(encode(row, col));
		}
	}

	queue<pair<int, int>> q;
	unordered_map<ull, int> dist;

	ull start = encode(x0, y0);
	ull target = encode(x1, y1);

	q.push({x0, y0});
	dist[start] = 0;

	int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
	int dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		ull cur = encode(x, y);

		if (cur == target) {
			cout << dist[cur] << '\n';
			return;
		}

		for (int i = 0; i < 8; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			ull next = encode(nx, ny);

			if (allowed.count(next) && dist.count(next) == 0) {
				dist[next] = dist[cur] + 1;
				q.push({nx, ny});
			}
		}
	}

	cout << -1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();

	return 0;
}
