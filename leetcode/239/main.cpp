class Solution {
  public:
	vector<int> maxSlidingWindow(vector<int>& arr, int k) {
		int n = arr.size();
		/*
            Assume k = 6

               0 1 2 3 4 5 6 7 8
                                  |
            1. [-------] | ...    |   entirely left
            2. ... [---|---] ...  |   crosses boundary
            3. ... | [-------]    |   entirely right

            1st case : ans[i] = max(left[4], right[0]) (here, both are same)
            3rd case : ans[i] = max(left[7], right[3]) (here, both are same)
            2nd case : Here, left[...] and right[...] will be different and
                       we need to consider the max = max(left[7], right[2])

                    left[7] means max within block [5, 7] inclusive
                    right[2] means max within block [4, 2] (meaning, from 2
                    to 4) inclusive
        */

		vector<int> left(n, 0), right(n, 0), ans;

		// Prefix maximum within each block
		for (int i = 0; i < n; ++i) {
			if (i % k == 0)
				left[i] = arr[i];
			else
				left[i] = max(left[i - 1], arr[i]);
		}

		// Suffix maximum within each block
		for (int i = n - 1; i >= 0; --i) {
			if (i == n - 1 || (i + 1) % k == 0)
				right[i] = arr[i];
			else
				right[i] = max(right[i + 1], arr[i]);
		}

		for (int i = 0; i <= n - k; ++i) {
			ans.emplace_back(max(right[i], left[i + k - 1]));
		}

		return ans;
	}
};

class Solution {
  public:
	vector<int> maxSlidingWindow(vector<int>& arr, int k) {

		int n = arr.size(), left = 0, right = 0;
		deque<int> dq;
		vector<int> ans;

		while (right < n) {

			while (!dq.empty() && arr[dq.back()] < arr[right]) {
				dq.pop_back();
			}

			dq.emplace_back(right);

			// remove elements out of the window
			if (left > dq[0]) {
				dq.pop_front();
			}

			// if window size is reached
			if (right >= (k - 1)) {
				ans.emplace_back(arr[dq.front()]);
				left++;
			}

			right++;
		}
		return ans;
	}
};
