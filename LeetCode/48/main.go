func transpose(mat [][]int) {
    n := len(mat)
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            mat[i][j], mat[j][i] = mat[j][i], mat[i][j]
        }
    }
}

func reverseRow(row []int) {
    l, r := 0, len(row) - 1
    for l < r {
        row[l], row[r] = row[r], row[l]
        l++
        r--
    }
}

func rotate(mat [][]int) {
    transpose(mat)

    for i := 0; i < len(mat); i++ {
        reverseRow(mat[i])
    }
}