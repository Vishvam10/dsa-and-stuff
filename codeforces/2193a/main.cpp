#include <iostream> // for cin, cout

using namespace std;

void solve() {
	int n, s, x;
	cin >> n >> s >> x;
	int arr[n + 5], sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	if (sum > s || (s - sum) % x != 0)
		cout << "NO" << "\n";
	else
		cout << "YES" << "\n";
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
