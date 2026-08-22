#include <algorithm> // for max, min, sort, etc.
#include <iostream>  // for cin, cout
#include <vector>    // for vector

using namespace std;

void solve() {
	int n, ans = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int left = 0, right = n - 1;
	while (left < right)
		ans += (arr[right--] - arr[left++]);
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
