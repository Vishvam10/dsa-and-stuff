#include <algorithm>
#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;

	int upper = count_if(s.begin(), s.end(), ::isupper);

	if (upper > s.length() / 2) {
		transform(s.begin(), s.end(), s.begin(), ::toupper);
	} else {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
	}

	cout << s << '\n';
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
