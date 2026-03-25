class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        sort(arr.begin(), arr.end());
        int cnt = 1, ans = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] == arr[i - 1]) {
                continue;
            } 
            else if (arr[i] == arr[i - 1] + 1) {
                cnt++;
            } 
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }

        return max(ans, cnt);
    }
};

// This gives TLE as worst case is O(N^2) is the input is sorted
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> set;
        for(const int& x : arr){
            set.insert(x);
        }
        int ans = 0;
        for(const int& x : arr){
            if(set.find(x - 1) == set.end()){
                int cur = x, cnt = 1;
                while(set.find(cur + 1) != set.end()){
                    cur++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};