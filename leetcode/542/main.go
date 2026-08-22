package main

type Cell struct {
	x    int
	y    int
	dist int
}

func updateMatrix(mat [][]int) [][]int {
	nRows, nCols := len(mat), len(mat[0])

	vis := make([][]bool, nRows)
	ans := make([][]int, nRows)

	for i := 0; i < nRows; i++ {
		vis[i] = make([]bool, nCols)
		ans[i] = make([]int, nCols)
	}

	q := make([]Cell, 0)

	for i := 0; i < nRows; i++ {
		for j := 0; j < nCols; j++ {
			if mat[i][j] == 0 {
				vis[i][j] = true
				q = append(q, Cell{i, j, 0})
			}
		}
	}

	dx := []int{-1, 1, 0, 0}
	dy := []int{0, 0, -1, 1}

	for len(q) > 0 {
		cell := q[0]
		q = q[1:]

		ans[cell.x][cell.y] = cell.dist

		for i := 0; i < 4; i++ {
			nx := cell.x + dx[i]
			ny := cell.y + dy[i]

			if nx >= 0 && nx < nRows &&
				ny >= 0 && ny < nCols &&
				!vis[nx][ny] {

				vis[nx][ny] = true
				q = append(q, Cell{nx, ny, cell.dist + 1})
			}
		}
	}

	return ans
}
