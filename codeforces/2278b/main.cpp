#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iterator>
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
    int x, y, z;
    cin >> x >> y >> z;

    // bob wins = at least the number of rounds won by Alice.
    // r s r s r s r s r s r s p
    // p p p p p p p p p p p s s

    char res = 'P';
    if(y >= x && y >= z) res = 'R';
    else if(z >= x && z >= y) res = 'S';

    string ans(x + y + z, res);
    cout << ans << "\n";
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
