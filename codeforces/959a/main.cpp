#include <cassert>
#include <iostream>

using namespace std;

void solve() {
	int n;
	cin >> n;
	cout << (n % 2 == 0 ? "Mahmoud" : "Ehab") << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc = 1;
	for (int t = 1; t <= tc; t++) {
		solve();
	}
}
