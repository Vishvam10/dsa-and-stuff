


class Solution {
public:

    int solve(
        int ind, int cnt, int sumA, int sumB,vector<int>& arr
    ) {

        if(ind == arr.size()) {
            if(cnt == arr.size() / 2) return abs(sumA - sumB);
            return INT_MAX;
        }

        int aDiff = solve(ind + 1, cnt + 1, sumA + arr[ind], sumB, arr);
        int bDiff = solve(ind + 1, cnt, sumA, sumB + arr[ind], arr);

        return min(aDiff, bDiff);
    }

    int minimumDifference(vector<int>& arr) {
        int n = arr.size();
        return solve(0, 0, 0, 0, arr);
    }
};