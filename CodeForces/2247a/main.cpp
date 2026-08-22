#include <iostream> // for cin, cout
#include <numeric>  // for reduce
#include <vector>   // for vector

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int s = accumulate(arr.begin(), arr.end(), 0);
	cout << ((s % 4 == 0) ? "YES" : "NO") << "\n";
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
