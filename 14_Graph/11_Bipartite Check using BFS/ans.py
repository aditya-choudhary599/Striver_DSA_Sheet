# Question Link : https://leetcode.com/problems/is-graph-bipartite/description/

from typing import List


class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = [-1] * n

        # We will do bfs traversal
        def bfs(start):
            queue = [start]
            color[start] = 0

            while queue:
                front = queue.pop(0)

                for con in graph[front]:
                    if color[con] == -1:
                        color[con] = 1 ^ color[front]
                        queue.append(con)
                    elif color[con] == color[front]:
                        return False

            return True

        ans = True
        for i in range(n):
            if color[i] == -1:
                ans = ans and bfs(i)
                if not ans:
                    return False

        return True
