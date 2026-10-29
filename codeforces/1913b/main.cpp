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
    string s;
    cin >> s;
    int ones = 0, zeros = 0;
    for(char ch : s) {
        if(ch == '0') zeros++;
        else ones++;
    }
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '0') {
            if(ones == 0) {
                cout << s.length() - i << "\n";
                return;
            }
            ones--;
        } else {
            if(zeros == 0) {
                cout << s.length() - i << "\n";
                return;
            }
            zeros--;
        }
    }
    cout << 0 << "\n";
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
