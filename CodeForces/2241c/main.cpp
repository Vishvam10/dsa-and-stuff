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
    int n;
    string s;
    cin >> n >> s;
    // Think of reductions. If there's 00 or 11, then ∧
    // can always reduce it to string of len 1
    for(int i = 1; i < n; ++i) {
        if(s[i - 1] == s[i]) {
            cout << "1" << "\n";
            return;
        }
    }
    // If we arrive here, it means the string was
    // alternating (1010.. or 0101...)
    cout << ((n % 2 == 0) ? "1" : "2") << "\n";
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
