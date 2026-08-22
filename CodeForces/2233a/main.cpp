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
using ll = long long int;

void solve() {
    ll n, x, y, z;
    cin >> n >> x >> y >> z;


    ll withoutZ = ceil(n / (x + y));
    ll withZ;
    if (x * z >= n) {
        withZ = ceil(n / x);
    } else {
        ll rem = n - x * z;
        withZ = z + ceil(rem / (x + (10 * y)));
    }

    cout << min(withZ, withoutZ) << '\n';
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
