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

void solve() {
    int n, q;
    cin >> n;

    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        if (s.length() != n) {
            cout << "NO\n";
            continue;
        }

        unordered_map<char, int> mp1;
        unordered_map<int, char> mp2;

        bool ok = true;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            int x = arr[i];

            if (mp1.count(c) && mp1[c] != x) {
                ok = false;
                break;
            }

            if (mp2.count(x) && mp2[x] != c) {
                ok = false;
                break;
            }

            mp1[c] = x;
            mp2[x] = c;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
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
