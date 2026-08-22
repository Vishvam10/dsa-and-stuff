#include <algorithm> // for max, min, sort, etc.
#include <iostream>  // for cin, cout
#include <vector>    // for vector

using namespace std;

#define READ(v)                                                                \
	for (auto& x : (v))                                                        \
	cin >> x
#define PRINT(v)                                                               \
	for (const auto& x : v)                                                    \
		cout << x << " ";

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<bool> ans(n, false);
	READ(arr);

	int left = 0;
	for (int i = n - 1; i >= 0; --i) {
		left = max(left, arr[i]);
		if (left > 0) {
			left--;
			ans[i] = true;
		}
	}
	PRINT(ans);
	cout << "\n";
	return;
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
