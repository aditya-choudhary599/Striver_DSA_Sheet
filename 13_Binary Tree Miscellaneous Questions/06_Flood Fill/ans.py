# Question Link : https://leetcode.com/problems/flood-fill/description/

from typing import List


class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:

        # Solved by bfs algo
        rows, cols = len(image), len(image[0])
        vis = [[False] * cols for i in range(rows)]

        q = []
        q.append([sr, sc])

        while len(q) != 0:
            front = q[0]

            if not vis[front[0]][front[1]]:
                vis[front[0]][front[1]] = True

                if front[0] - 1 >= 0 and image[front[0] - 1][front[1]] == image[front[0]][front[1]]:
                    q.append([front[0] - 1, front[1]])

                if front[1] + 1 < cols and image[front[0]][front[1] + 1] == image[front[0]][front[1]]:
                    q.append([front[0], front[1] + 1])

                if front[0] + 1 < rows and image[front[0] + 1][front[1]] == image[front[0]][front[1]]:
                    q.append([front[0] + 1, front[1]])

                if front[1] - 1 >= 0 and image[front[0]][front[1] - 1] == image[front[0]][front[1]]:
                    q.append([front[0], front[1] - 1])

            image[front[0]][front[1]] = color
            del (q[0])

        return image
