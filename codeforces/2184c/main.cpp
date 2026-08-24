#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>


using namespace std;
using ll = long long int;

ll check(ll n, ll k, unordered_map<ll, ll>& mp) {
    if (n == k) return 0;
    if (n < k) return LLONG_MAX;

    if (mp.find(n) != mp.end()) return mp[n];

    ll a = check(n / 2, k, mp);
    ll b = check((n + 1) / 2, k, mp);

    ll best = min(a, b);

    if (best == LLONG_MAX)
        return mp[n] = LLONG_MAX;

    return mp[n] = best + 1;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    // check(n) --> min(
    //      check(ceil(n / 2)), check(floor(n / 2)
    // )

    unordered_map<ll, ll> mp;

    ll ans = check(n, k, mp);

    cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
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
