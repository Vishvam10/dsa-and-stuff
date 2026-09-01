#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << min({
	    abs(a - b) + abs(b - c),
	    abs(a - b) + abs(a - c),
	    abs(c - b) + abs(a - c),
	});
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
