// Number of subarrays ending at i = i - left + 1
class Solution {
public:
    long long countSubarrays(vector<int>& arr, int minK, int maxK) {
        int n = arr.size(), left = 0;
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            if (arr[i] < minK || arr[i] > maxK) left = i + 1;
            else ans += i - left + 1;
        }

        return ans;

        // OR, we can do this as well :

        // int len = 0;

        // for (int x : nums) {
        //     len = (x >= minK && x <= maxK) ? len + 1 : 0;
        //     ans += len;
        // }

        // return ans;

    }
};
