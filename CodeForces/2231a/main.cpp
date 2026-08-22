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
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;

    // 1 2 3 4 5 6 7 8 9 10 11 12 (n = 6)
    // [12, 11], [10, 9], [8, 7] => 12 11 10 9 8 7 23 22 10 17 15

    for(int i = 2 * n; i > n; --i) cout << i << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solve();
    }
}
