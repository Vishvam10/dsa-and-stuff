#include <algorithm> // for max, min, sort, etc.
#include <cctype>
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
    string s;
    cin >> s;
    if (
        all_of(s.begin(), s.end(), ::isupper) ||
        (
            islower(s[0]) &&
            all_of(s.begin() + 1, s.end(), ::isupper)
        )
    ) {
        for (char &c : s) c = isupper(c) ? tolower(c) : toupper(c);
    }
    cout << s << "\n";
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
