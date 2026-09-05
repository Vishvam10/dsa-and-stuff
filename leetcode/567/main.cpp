class Solution {
  public:
	bool checkInclusion(string s1, string s2) {
		if (s1.length() > s2.length())
			return false;
		int n = s1.length();

		vector<int> mp1(26, 0), mp2(26, 0);

		for (int i = 0; i < n; i++) {
			mp1[s1[i] - 'a']++;
			mp2[s2[i] - 'a']++;
		}

		if (mp1 == mp2)
			return true;

		for (int i = n; i < s2.length(); i++) {
			mp2[s2[i - n] - 'a']--;
			mp2[s2[i] - 'a']++;
			if (mp1 == mp2)
				return true;
		}

		return false;
	}
};
