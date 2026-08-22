#include <algorithm> // for max, min, sort, etc.
#include <climits>   // for LLONG_MAX
#include <cmath>     // for sqrt, round
#include <iostream>  // for cin, cout
#include <string>    // for string operations

using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0, ans = INT_MIN;
	for (const char ch : s) {
		if (ch == '#') {
			cnt++;
		} else {
			ans = max(ans, cnt);
			cnt = 0;
		}
	}
	ans = max(ans, cnt);
	cout << ceil(ans / 2.0) << "\n";
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
