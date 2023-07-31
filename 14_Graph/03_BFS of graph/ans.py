# Question Link : https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

from typing import List


class Solution:
    # Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, n: int, adj: List[List[int]]) -> List[int]:
        queue = []
        vis = [False] * n
        queue.append(0)
        ans = []

        while len(queue) != 0:
            front = queue[0]

            if not vis[front]:
                vis[front] = True
                ans.append(front)

                for num in adj[front]:
                    queue.append(num)

            del queue[0]

        return ans
