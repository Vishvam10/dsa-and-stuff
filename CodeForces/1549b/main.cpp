#include <iostream> // for cin, cout
#include <string>   // for string operations

using namespace std;

void solve() {
	int n;
	string a, b;
	cin >> n >> a >> b;
	int ans = 0;
	// a a _ _ _ a a
	// b b b b b b b
	// Y Y Y Y Y Y Y ... just look at local stuff ?
	for (int i = 0; i < n; ++i) {
		if (b[i] == '0')
			continue;
		if (a[i] == '0') {
			ans++;
			continue;
		}
		if (i > 0 && a[i - 1] == '1') {
			ans++;
			a[i - 1] = '2';
		} else if (i + 1 < n && a[i + 1] == '1') {
			ans++;
			a[i + 1] = '2';
		}
	}
	cout << ans << "\n";
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
