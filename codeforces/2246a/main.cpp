#include <iostream> // for cin, cout

using namespace std;

void solve() {
	int n;
	cin >> n;
	for (int i = n; i >= 1; --i)
		cout << i << " ";
	cout << "\n";
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
