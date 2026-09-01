#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

void solve() {
	int n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	for (int i = 0; i < t; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			if (s[j] == 'B' && s[j + 1] == 'G') {
				swap(s[j], s[j + 1]);
				j++;
			}
		}
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
