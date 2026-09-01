#include <algorithm> // for is_sorted
#include <iostream>  // for cin, cout
#include <vector>    // for vector

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	if (is_sorted(arr.begin(), arr.end()))
		cout << 0;
	else if (arr[0] == 1 || arr[n - 1] == n)
		cout << 1;
	else if (arr[0] == n && arr[n - 1] == 1)
		cout << 3;
	else
		cout << 2;
	cout << "\n";
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
