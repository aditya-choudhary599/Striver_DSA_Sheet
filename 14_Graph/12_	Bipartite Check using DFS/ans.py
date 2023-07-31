# Question Link : https://leetcode.com/problems/is-graph-bipartite/description/

from typing import List


class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1] * n

        # We will do dfs traversal
        def dfs(idx):
            for con in graph[idx]:
                if color[con] == color[idx]:
                    return False
                elif color[con] == -1:
                    color[con] = 1 ^ color[idx]
                    if not dfs(con):
                        return False

            return True

        ans = True
        for i in range(n):
            if color[i] == -1:
                color[i] = 0
                ans = ans and dfs(i)
                if not ans:
                    return False

        return True
