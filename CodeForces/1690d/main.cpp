#include <algorithm> // for max, min, sort, etc.
#include <climits>   // for LLONG_MAX
#include <iostream>  // for cin, cout
#include <string>    // for string operations
#include <vector>    // for vector

using namespace std;

void solve() {
	int n, k, ans = INT_MAX;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> pre(n + 1, 0);
	// min ops in a window of size k => min ops = no. of whites in
	// that window so prefix sum
	for (int i = 0; i < n; ++i)
		pre[i + 1] = pre[i] + (s[i] == 'W');
	for (int i = k; i <= n; ++i)
		ans = min(ans, (pre[i] - pre[i - k]));
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
