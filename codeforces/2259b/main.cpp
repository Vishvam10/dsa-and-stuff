#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;

	// parity of the dividend as well ... for 0/2, 1 is set
	// odd-odd and even-even are always in sync ... either with
	// 0 or with 2

	// 1 2 3 4
	// 2 4 6 8
	// 0 2 4 6
	// 2 0 2 4
	// 0 2 0 2
	// 2 0 2 0
	// 0 2 0 2

	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x % 2 == 1) {
			arr[i] = -1;
		} else {
			arr[i] = (x / 2) % 2;
		}
	};
	int ones = 0, zeros = 0, twos = 0;
	for (int i = 0; i < n; ++i) {
		ones += (arr[i] == -1);
		zeros += (arr[i] == 0);
		twos += (arr[i] == 1);
	}
	cout << max({ones, zeros, twos}) << "\n";
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
