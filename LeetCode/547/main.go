package main

func dfs(node int, graph [][]int, vis []bool) {

	vis[node] = true

	for nei := 0; nei < len(graph); nei++ {
		if graph[node][nei] == 1 && !vis[nei] {
			dfs(nei, graph, vis)
		}
	}

}

func findCircleNum(graph [][]int) int {

	n := len(graph)
	vis := make([]bool, n)
	ans := 0

	for i := 0; i < n; i++ {
		if !vis[i] {
			ans++
			dfs(i, graph, vis)
		}
	}

	return ans
}
