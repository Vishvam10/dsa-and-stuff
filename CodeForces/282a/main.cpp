#include <iostream> // for cin, cout
#include <string>   // for string operations

using namespace std;

void solve() {
	int n, ans = 0;
	cin >> n;
	string val;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		if (val[0] == '-' || val[1] == '-' || val[2] == '-')
			ans--;
		else
			ans++;
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
