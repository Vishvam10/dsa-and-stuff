package main

func checkValidString(s string) bool {
	n := len(s)
	// Instead of cnt, we now have a pair : [cnt1, cnt2]
	cnt1, cnt2 := 0, 0
	for i := 0; i < n; i++ {
		if s[i] == '(' {
			cnt1++
			cnt2++
		} else if s[i] == ')' {
			cnt1--
			cnt2--
		} else {
			// treat as ')'
			cnt1--
			// treat as '('
			cnt2++
		}

		// Meaning, we have more number of close than open
		if cnt2 < 0 {
			return false
		}
		if cnt1 < 0 {
			cnt1 = 0
		}
	}

	return cnt1 == 0
}
