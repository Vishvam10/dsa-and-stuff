#include <cmath> // for sqrt, round
#include <cstddef>
#include <iostream> // for cin, cout
#include <vector>   // for vector

using namespace std;

bool is_strictly_sorted(const vector<int>& v) {
	for (size_t i = 1; i < v.size(); ++i) {
		if (v[i - 1] >= v[i])
			return false;
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n - 1; ++i) {
		int req = abs(arr[i] - i - 1);
		arr[i] -= req;
		arr[i + 1] += req;
	}
	cout << (is_strictly_sorted(arr) ? "YES" : "NO") << "\n";
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
