#include <algorithm> // for max, min, sort, etc.
#include <climits>   // for LLONG_MAX
#include <iostream>  // for cin, cout
#include <vector>    // for vector

using namespace std;
using ll = long long int;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n), pre(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int i = 0, j = n - 1;
	ll ls = 0, rs = 0, ans = LLONG_MIN;
	while (i <= j) {
		if (ls <= rs)
			ls += arr[i++];
		else
			rs += arr[j--];
		if (ls == rs)
			ans = max(ans, ls);
	}
	cout << (ans == LLONG_MIN ? 0 : ans) << "\n";
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
