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
    string s;
    cin >> s;
    int ans = 0;

    // a 1 0 1 1 0 1 b => even pal can always be reduced to 1 ?
    // a 1 0 0 0 1 b => odd pal can always be reduced to 1 ?
    // 0 ... 1 => becomes 2 ... so only cases are 1 and 2 .. ?

    for(int i = 0; i < n - 1; ++i) ans += (s[i] != s[i + 1]);
    cout << ((ans == 1) ? 2 : 1) << "\n";

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
