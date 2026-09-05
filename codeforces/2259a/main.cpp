#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	int ans = 0;
	// [1 0] [0 1] [1 1] [0 0]

	for (int i = 0; i < n; i += k) {
		ans += s.substr(i, k).find('0') == string::npos ? 1 : 0;
	}
	cout << ans << "\n";
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
