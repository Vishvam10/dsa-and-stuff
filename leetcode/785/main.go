package main

func isBipartite(graph [][]int) bool {
	n := len(graph)

	// -1 is unvisited, 0 and 1 are colors
	color := make([]int, n)
	for i := 0; i < n; i++ {
		color[i] = -1
	}

	for start := 0; start < n; start++ {
		if color[start] != -1 {
			continue
		}

		queue := []int{start}
		color[start] = 0

		for len(queue) > 0 {
			node := queue[0]
			queue = queue[1:]

			for _, neigh := range graph[node] {
				if color[neigh] == -1 {
					// assign opposite color
					color[neigh] = 1 - color[node]
					queue = append(queue, neigh)
				} else if color[neigh] == color[node] {
					return false
				}
			}
		}
	}

	return true
}
