#include <iostream>      // for cin, cout
#include <unordered_map> // for unordered_map
#include <vector>        // for vector

using namespace std;

void solve() {
	int n, v;
	cin >> n;
	// from -> to
	unordered_map<int, int> mp;
	vector<int> ans(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> v;
		mp[i] = v;
	}
	for (int i = 1; i <= n; ++i) {
		vector<bool> vis(n + 1, false);
		int cur = i;
		while (!vis[cur]) {
			vis[cur] = true;
			cur = mp[cur];
		}
		ans[i] = cur;
	}
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	cout << "\n";
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
