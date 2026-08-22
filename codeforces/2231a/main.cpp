#include <iostream> // for cin, cout

using namespace std;

void solve() {
	int n;
	cin >> n;

	// 1 2 3 4 5 6 7 8 9 10 11 12 (n = 6)
	// [12, 11], [10, 9], [8, 7] => 12 11 10 9 8 7 23 22 10 17 15

	for (int i = 2 * n; i > n; --i)
		cout << i << " ";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}
