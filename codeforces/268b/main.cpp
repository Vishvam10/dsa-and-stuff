#include <cassert>
#include <iostream>

using namespace std;
using ull = unsigned long long int;

void solve() {
	ull n;
	cin >> n;

	// Say the sequence is (1, 2, 3, ... n)
	// Now, worst case would be (n - 1) wrong presses at 1,
	// then (n - 2) wrong presses at 2, ... 1 wrong press at n
	// And each wrong move at position "i" needs :
	// (i + 1)(n − i − 1)
	//
	// -> i + 1       : 1 moves for correction for pos "i" and i
	//                  moves for trying out wrong stuff at pos "i"
	// -> (n - i - 1) : the number of previous elements that are
	//                  affected by the worng move and require
	//                  these many moves to correct

	// Ans = sum of (i * (n - i) + 1) ... either we can use a for
	// loop OR expand to get a closed form solution ...
	//
	// ans = sum(n * i - i ^ 2 + 1) = n * sum(i) + sum(i^2) + sum(1)
	//     = (n * (n * (n + 1) / 2)) + (n * (n + 1) * (2 * n + 1)) / 6 + n
	//     = (n * (n ^ 2 + 5)) / 6

	cout << ((n * (n * n + 5)) / 6) << "\n";
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
