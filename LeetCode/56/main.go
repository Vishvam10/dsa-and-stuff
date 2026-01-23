package main

import (
	"cmp"
	"slices"
)

func merge(arr [][]int) [][]int {

	n := len(arr)

	slices.SortFunc(arr, func(a, b []int) int {
		return cmp.Compare(a[0], b[0])
	})

	ans := [][]int{arr[0]}

	for i := 1; i < n; i++ {
		prev, cur := ans[len(ans)-1], arr[i]

		if cur[0] >= prev[0] && cur[0] <= prev[1] {
			mn, mx := min(cur[0], prev[0]), max(cur[1], prev[1])
			ans[len(ans)-1] = []int{mn, mx}
		} else {
			ans = append(ans, arr[i])
		}
	}

	return ans

}
