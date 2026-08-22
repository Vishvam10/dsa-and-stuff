#include <iostream> // for cin, cout
#include <string>   // for string operations

using namespace std;

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	bool c0 = 0, c1 = 0;
	for (int i = 0; i < n; i++) {
		if (!c0 && s[i] == '0') {
			c0 = true;
			continue;
		}
		if (!c1 && s[i] == '1') {
			c1 = true;
			continue;
		}
		cout << s[i];
	}
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
