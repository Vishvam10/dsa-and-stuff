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
    char ch;
    string s;
    cin >> n >> ch >> s;
    s += s;
    // r g g r y => r g g r y r g g r y
    // r g g r y r g g r y
    int start = 0, ans = INT_MIN;
    for(int i = 2 * n - 1; i >= n; --i) {
        if(s[i] == 'g') start = i;
    }
    for(int i = n - 1; i >= 0; --i) {
        if(s[i] == 'g') start = i;
        else if(s[i] == ch) ans = max(ans, start - i);
    }
    cout << (ans == INT_MIN ? 0 : ans) << "\n";

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
