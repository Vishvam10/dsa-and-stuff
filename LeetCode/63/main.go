package main

func solve(i int, j int, dp [][]int, mat [][]int, nRows int, nCols int) int {

	if i >= nRows || i < 0 || j < 0 || j >= nCols {
		return 0
	}

	if mat[i][j] == 1 {
		return 0
	}

	if i == nRows-1 && j == nCols-1 {
		return 1
	}

	if dp[i][j] != -1 {
		return dp[i][j]
	}

	right := solve(i+1, j, dp, mat, nRows, nCols)
	down := solve(i, j+1, dp, mat, nRows, nCols)

	dp[i][j] = right + down
	return dp[i][j]
}

func uniquePathsWithObstacles(mat [][]int) int {
	nRows, nCols := len(mat), len(mat[0])
	dp := make([][]int, nRows)
	for i := 0; i < nRows; i++ {
		dp[i] = make([]int, nCols)
		for j := 0; j < nCols; j++ {
			dp[i][j] = -1
		}
	}
	return solve(0, 0, dp, mat, nRows, nCols)
}
