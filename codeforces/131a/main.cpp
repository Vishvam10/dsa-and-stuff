#include <algorithm> // for max, min, sort, etc.
#include <cctype>
#include <iostream> // for cin, cout
#include <string>   // for string operations

using namespace std;

void solve() {
	string s;
	cin >> s;
	if (all_of(s.begin(), s.end(), ::isupper) ||
	    (islower(s[0]) && all_of(s.begin() + 1, s.end(), ::isupper))) {
		for (char& c : s)
			c = isupper(c) ? tolower(c) : toupper(c);
	}
	cout << s << "\n";
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
