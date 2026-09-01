#include <algorithm>
#include <iostream> // for cin, cout
#include <vector>   // for vector

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int mx = *max_element(arr.begin(), arr.end());
	int mn = *min_element(arr.begin(), arr.end());
	int ans = mx - mn + 1;
	bool same = true;
	for (int i = 0; i < n; ++i) {
		if (arr[i] != arr[0]) {
			same = false;
			break;
		}
	}
	cout << ((same) ? 1 : ans) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve();
	}
}
