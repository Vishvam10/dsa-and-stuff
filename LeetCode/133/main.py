"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:

    def cloneGraph(self, root: Optional['Node']) -> Optional['Node']:
        if not root :
            return None

        vis = {}

        def dfs(node) :
            if node in vis :
                return vis[node]
            
            new_node = Node(node.val)
            vis[node] = new_node
            
            for nei in node.neighbors :
                new_neighbor = dfs(nei)
                new_node.neighbors.append(new_neighbor)

            return new_node
        
        return dfs(root)