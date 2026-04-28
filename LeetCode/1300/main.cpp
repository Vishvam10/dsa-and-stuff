class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int low = 0, high = *max_element(arr.begin(), arr.end());
        int best = 0, bestDiff = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int sum = 0;
            for (int x : arr) sum += min(x, mid);

            int diff = abs(sum - target);

            if (diff < bestDiff || (diff == bestDiff && mid < best)) {
                bestDiff = diff;
                best = mid;
            }

            if (sum < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return best;
    }
};