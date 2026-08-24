#include <algorithm>
#include <iostream>  // for cin, cout
#include <vector>    // for vector

using namespace std;

bool simulate(vector<int> arr, int n, int height) {
    for(int i = 0; i < n; ++i) {
        if(arr[i] > height) {
            arr[i] -= height;
            if(i + 1 < n) {
                arr[i + 1] += height;
            }
        }
    }
    for(int i = 0; i < n; ++i) if(arr[i] != arr[0]) return false;
    return true;
}

void solve(int t) {
    cout << "CASE : " << t << "\n";
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            ans[i] = arr[0];
            continue;
        }
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());

        while(low < high) {
            int mid = low + (high - low) / 2;
            // decrease height here because even after simulation, there are few
            // elements who have a height < whatever was added on top of it
            if(!simulate(arr, i, mid)) {
                cout << "REACHED : " << mid << "\n";
                high = mid - 1;
            } else {
                low = mid;
            }
        }

        ans[i] = low;
    }

    for(const auto&x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        solve(i);
    }
}
