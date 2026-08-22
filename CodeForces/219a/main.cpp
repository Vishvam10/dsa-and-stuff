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
    int k;
    cin >> k;
    string s;
    cin >> s;

    unordered_map<char, int> mp;

    for (char c : s) mp[c]++;
    for (auto [c, f] : mp) {
        if (f % k != 0) {
            cout << -1 << '\n';
            return;
        }
    }

    string pre, ans;

    for (auto [c, f] : mp) pre += string(f / k, c);
    for (int i = 0; i < k; i++) ans += pre;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
