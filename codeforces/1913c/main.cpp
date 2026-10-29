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


bool check(int val, array<int, 30> mp) {
    for (int i = 29; i >= 0; --i) {
        int quo = min(mp[i], val / (1 << i));
        val -= quo * (1 << i);
    }
    return val == 0;
}

void solve() {
    int n;
    cin >> n;
    array<int, 30> mp = {0};
    for (int i = 0; i < n; ++i) {
        int type, val;
        cin >> type >> val;
        if (type == 1) {
            mp[val]++;
        } else {
            bool res = check(val, mp);
            cout << (res ? "YES" : "NO") << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
