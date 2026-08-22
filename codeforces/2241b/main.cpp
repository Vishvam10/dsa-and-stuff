#include <iostream> // for cin, cout

using namespace std;
using ull = unsigned long long int;

bool good(ull n) {
	int arr[10] = {0};
	int cnt = 0;

	if (n == 0)
		arr[0]++;

	while (n > 0) {
		arr[n % 10]++;
		n /= 10;
	}

	for (int i = 0; i < 10; ++i)
		cnt += arr[i] > 0;
	return cnt > 0 && cnt <= 2;
}

void solve() {
	ull x;
	cin >> x;
	for (ull i = 2; i <= 1e9; ++i) {
		if (good(i) && good(x * i)) {
			cout << i << "\n";
			return;
		}
	}
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
