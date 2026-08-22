#include <algorithm>  // for max, min, sort, etc.
#include <climits>    // for LLONG_MAX
#include <cmath>      // for sqrt, round
#include <iostream>   // for cin, cout
#include <limits>     // for numeric_limits if needed
#include <map>        // for map
#include <numeric>    // for reduce
#include <queue>      // for queue
#include <set>        // for set
#include <sstream>    // for getline
#include <string>     // for string operations
#include <vector>     // for vector

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if (k == n - 1) {
        cout << -1 << "\n";
        return;
    }

    // Fill up the 2 * k positions first with then alternate ?
    // 000... | 111... | 0 | 1 | ... to keep the diff of of
    // num(1) - num(0) <= 1
    //
    // 00 => 1, 000 => 2, 0000 => 3, so we need (n + 1) for n pairs

    int cnt0 = (n + 1) / 2;
    int cnt1 = n / 2;

    int k0 = k / 2;
    int k1 = k - k0;

    if (!(k0 + 1 <= cnt0 && k1 + 1 <= cnt1)) swap(k0, k1);

    // If the first split fits but leaves an invalid remainder,
    // try the other split.
    auto canAlternate = [&]() {
        int rem0 = cnt0 - (k0 + 1);
        int rem1 = cnt1 - (k1 + 1);
        return rem0 >= 0 && rem1 >= 0 && abs(rem0 - rem1) <= 1;
    };

    if (!canAlternate()) swap(k0, k1);

    if (k0 + 1 > cnt0 || k1 + 1 > cnt1 || !canAlternate()) {
        cout << -1 << "\n";
        return;
    }

    string ans;

    ans += string(k0 + 1, '0');
    ans += string(k1 + 1, '1');

    cnt0 -= k0 + 1;
    cnt1 -= k1 + 1;

    char last = '1';

    while (cnt0 || cnt1) {
        if (last == '1' && cnt0) {
            ans += '0';
            --cnt0;
            last = '0';
        }
        else if (last == '0' && cnt1) {
            ans += '1';
            --cnt1;
            last = '1';
        }
    }

    cout << ans << '\n';
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
