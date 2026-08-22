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

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < m; ++i) cin >> b[i];

  if(n < 2 * m) {
      cout << "NO" << "\n";
      return;
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int i = 0;
  // Optimal way is to offset by (n - m) first instead of pairing
  // i and (n - i)
  while(i < m && b[i] > a[i] && b[i] < a[n - m + i]) i++;
  cout << (i < m ? "NO" : "YES") << "\n";
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
