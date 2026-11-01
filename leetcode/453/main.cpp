class Solution {
public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();
        int s = accumulate(arr.begin(), arr.end(), 0ll);
        int mn = *min_element(arr.begin(), arr.end());
        return s - (n * mn);
    }
};
