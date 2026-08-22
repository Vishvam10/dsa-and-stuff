#include <cctype>
#include <iostream> // for cin, cout
#include <string>   // for string operations

using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	// diverse if and only if there is no letter to
	// appear strictly more than n / 2 times
	//
	// len 2 substr of type ab => ALWAYS

	for (int i = 0; i < n - 1; ++i) {
		if (s[i] != s[i + 1]) {
			cout << "YES" << "\n";
			cout << s[i] << s[i + 1] << "\n";
			return;
		}
	}

	cout << "NO" << "\n";
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
