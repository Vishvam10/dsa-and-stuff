#include <algorithm> // for max, min, sort, etc.
#include <iostream>  // for cin, cout

using namespace std;

void solve() {
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr, arr + 3);
	cout << min(arr[2] - arr[0], arr[1]) << "\n";
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
