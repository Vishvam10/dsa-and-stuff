#include <algorithm> // for max, min, sort, etc.
#include <iostream>  // for cin, cout
#include <string>    // for string operations

using namespace std;

void solve() {
	string s;
	cin >> s;
	auto start = s.find_first_of("1");
	auto end = s.find_last_of("1");
	if (start == string::npos) {
		cout << 0 << "\n";
		return;
	}
	string temp = s.substr(start, end - start + 1);
	int ans = count(temp.begin(), temp.end(), '0');
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
