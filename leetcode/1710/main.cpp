class Solution {
  public:
	int maximumUnits(vector<vector<int>>& arr, int k) {
		int n = arr.size(), ans = 0;
		sort(arr.begin(), arr.end(),
		     [](const vector<int>& a, const vector<int>& b) {
			     return a[1] > b[1];
		     });
		for (int i = 0; i < n; ++i) {
			int num = arr[i][0], units = arr[i][1];
			int take = min(k, num);
			ans += (take * units);
			k -= take;
			if (k == 0)
				break;
		}
		return ans;
	}
};
