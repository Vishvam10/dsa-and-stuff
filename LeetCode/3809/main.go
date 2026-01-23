package main

import (
	"cmp"
	"slices"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func bestTower(towers [][]int, center []int, radius int) []int {

	n := len(towers)
	ans := [][]int{}
	cx, cy := center[0], center[1]

	for i := 0; i < n; i++ {
		tower := towers[i]
		x, y, quality := tower[0], tower[1], tower[2]

		if abs(x-cx)+abs(y-cy) <= radius {
			ans = append(ans, []int{x, y, quality})
		}
	}

	if len(ans) == 0 {
		return []int{-1, -1}
	}

	slices.SortFunc(ans, func(a, b []int) int {
		return cmp.Or(
			cmp.Compare(b[2], a[2]),
			cmp.Compare(a[0], b[0]),
			cmp.Compare(a[1], b[1]),
		)
	})

	return []int{ans[0][0], ans[0][1]}

}
