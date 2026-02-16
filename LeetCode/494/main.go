package main

type Key struct {
	pos int
	sum int
}

func findTargetSumWays(arr []int, target int) int {
	mp := make(map[Key]int)

	var helper func(int, int) int
	helper = func(pos int, res int) int {

		// Base case
		if pos == len(arr) {
			if res == target {
				return 1
			}
			return 0
		}

		key := Key{pos, res}

		if val, ok := mp[key]; ok {
			return val
		}

		// pick +
		a := helper(pos+1, res+arr[pos])

		// pick -
		b := helper(pos+1, res-arr[pos])

		mp[key] = a + b
		return mp[key]
	}

	return helper(0, 0)
}
