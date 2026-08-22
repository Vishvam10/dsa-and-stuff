#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long int;

vector<vector<int>> tree;
vector<ll> cnt;

void traverse(int node, int par) {
	if (tree[node][0] == par && tree[node].size() == 1) {
		cnt[node] = 1;
		return;
	}

	for (auto child : tree[node]) {
		if (child != par) {
			traverse(child, node);
			cnt[node] += cnt[child];
		}
	}
}
void solve() {
	int n, q;
	cin >> n;

	tree.assign(n, vector<int>());

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	cnt.assign(n, 0);
	traverse(0, -1);

	cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;

		ll res = cnt[x] * cnt[y];
		cout << res << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		solve();
	}
}
