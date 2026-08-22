package main

func bfs(x int, y int, nRows int, nCols int, actual int, target int, mat *[][]int) {

	if x < 0 || x >= nRows || y < 0 || y >= nCols {
		return
	}

	if (*mat)[x][y] != actual || (*mat)[x][y] == target {
		return
	}

	(*mat)[x][y] = target

	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1}

	for i := 0; i < 4; i++ {
		bfs(x+dx[i], y+dy[i], nRows, nCols, actual, target, mat)
	}
}

func floodFill(image [][]int, sr int, sc int, color int) [][]int {
	nRows, nCols := len(image), len(image[0])
	actual := image[sr][sc]
	if actual != color {
		bfs(sr, sc, nRows, nCols, actual, color, &image)
	}
	return image
}
