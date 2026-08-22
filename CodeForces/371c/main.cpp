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
    string s;
    cin >> s;

    ll nb, ns, nc, pb, ps, pc, r, rb = 0, rs = 0, rc = 0;
    cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;

    for (char c : s) {
        if (c == 'B') rb++;
        else if (c == 'S') rs++;
        else rc++;
    }

    ll low = 0, high = 1e13;

    auto f = [&](ll numHams) {
        ll bCost = max(0LL, rb * numHams - nb) * pb;
        ll cCost = max(0LL, rc * numHams - nc) * pc;
        ll sCost = max(0LL, rs * numHams - ns) * ps;
        ll total = bCost + cCost + sCost;
        return total <= r;
    };

    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(!f(mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << high << '\n';
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
