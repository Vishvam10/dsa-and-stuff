#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	// R G G B R B B G R R
	for (int i = 0; i < n - 1; ++i)
		ans += (s[i] == s[i + 1]);
	cout << ans << "\n";
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
