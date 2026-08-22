#include <iostream> // for cin, cout

using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
	// int longs = (x / 2) + (y / 2);
	int shorts = (x % 2) + (y % 2);
	if (shorts > 1) {
		cout << "NO" << "\n";
	} else {
		cout << "YES" << "\n";
	}
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
