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
    int nRows, nCols;
    cin >> nRows >> nCols;
    vector<vector<int>> A(nRows, vector<int>(nCols, 1));
    vector<vector<int>> B(nRows, vector<int>(nCols, 0));
    for(int i = 0; i < nRows; ++i) {
        for(int j = 0; j < nCols; ++j) {
            cin >> B[i][j];
        }
    }

    for(int i = 0; i < nRows; ++i) {
        for(int j = 0; j < nCols; ++j) {
            if(B[i][j] == 0) {
                for(int k = 0; k < nRows; ++k) A[k][j] = 0;
                for(int k = 0; k < nCols; ++k) A[i][k] = 0;
            }
        }
    }

    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            int res = 0;
            for (int k = 0; k < nRows; ++k) res |= A[k][j];
            for (int k = 0; k < nCols; ++k) res |= A[i][k];

            if (res != B[i][j]) {
                cout << "NO" << "\n";
                return;
            }
        }
    }

    cout << "YES\n";

    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

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
