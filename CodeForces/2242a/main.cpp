#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream> // for cin, cout

using namespace std;

void solve() {
	int n;
	cin >> n;
	int val = 0, a = INT_MIN, cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		a = max(a, val);
		cnt += (val == 2);
	}
	if (a > 2 || cnt > 1) {
		cout << "YES" << "\n";
	} else {
		cout << "NO" << "\n";
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
