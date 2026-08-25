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
    int n, op = 0, cnt = 0;
    string s;
    cin >> n >> s;

    // stack<char> st;

    // for(int i = 0; i < n; ++i) {
    //     char ch = s[i];
    //     if(ch == '(') {
    //         st.push(ch);
    //     } else {
    //         if(st.empty()) {
    //             cnt++;
    //         } else {
    //             st.pop();
    //         }
    //     }
    // }

    for (char ch : s) {
        if (ch == '(') op++;
        else if (op > 0) op--;
        else cnt++;
    }

    cout << cnt << "\n";
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
