#include <cassert>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n, 0);

	// range [l, r] --> count of 1s
	map<pair<int, int>, int> mp;

	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		mp[{l, r}] = 0;
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		int ind;
		cin >> ind;
		// find all intervals having ind ... so,
		// p.firs >= x <= p.second for all p's ?
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
