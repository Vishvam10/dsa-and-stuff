class Solution {
public:
    int hIndex(vector<int>& arr) {
        // 6 5 3 1 0
        int ans = INT_MIN;
        sort(arr.rbegin(), arr.rend());
        for(int i = 0; i < arr.size(); ++i) {
            int cit = i, req = arr[i];
            if(cit >= req) return cit;
        }
        return arr.size();
    }
};

// OR this
//
class Solution {
  public:
	int hIndex(vector<int>& arr) {

		int n = arr.size();
		int ans = 0;

		sort(arr.begin(), arr.end());

		for (int i = 0; i < n; i++) {
			int key = min(arr[i], n - i);
			ans = max(ans, key);
		}

		return ans;
	}
};
