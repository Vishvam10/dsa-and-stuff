#include <algorithm> // for max, min, sort, etc.
#include <climits>   // for LLONG_MAX
#include <cmath>     // for sqrt, round
#include <iostream>  // for cin, cout
#include <limits>    // for numeric_limits if needed
#include <map>       // for map
#include <numeric>   // for reduce
#include <queue>     // for queue
#include <set>       // for set
#include <sstream>   // for getline
#include <string>    // for string operations
#include <vector>    // for vector

using namespace std;
using ll = long long int;

void solve() {
    ll n, m, i, j;
    cin >> n >> m >> i >> j;

    ll d1 = abs(i - 1) + abs(j - 1) + abs(i - n) + abs(j - m);
    ll d2 = abs(i - 1) + abs(j - m) + abs(i - n) + abs(j - 1);

    if (d1 >= d2) {
        cout << 1 << " " << 1 << " " << n << " " << m << '\n';
    } else {
        cout << 1 << " " << m << " " << n << " " << 1 << '\n';
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
