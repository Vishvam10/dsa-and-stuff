#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	// Take out the parent ... that leaves with all children
	// in a single group ... do that recursively ?
	// Then club the leaf nodes with the ones with no
	// manager folks ?

	//         1           5
	//     2       4
	// 3
	//
	// Groups : [1], [2, 4], [3, 5]
	// ... Level order traversal ? But club all the trees
	// into 1 using a dummy node ...

	// par --> children and 0 = dummy node
	vector<vector<int>> tree(n + 1);
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		if (p == -1)
			tree[0].push_back(i);
		else
			tree[p].push_back(i);
	}

	int ans = 0;
	q.push(0);

	while (!q.empty()) {
		int sz = q.size();
		for (int i = 0; i < sz; ++i) {
			int node = q.front();
			q.pop();
			for (int& ch : tree[node])
				q.push(ch);
		}
		ans++;
	}

	// Dummy level should not be counted
	cout << ans - 1 << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	for (int t = 1; t <= tc; t++) {
		solve();
	}
}
