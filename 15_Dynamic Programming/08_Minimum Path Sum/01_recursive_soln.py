# Question Link : https://leetcode.com/problems/minimum-path-sum/

from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        def dfs(i: int, j: int):
            if i >= m or j >= n:
                return 1e9

            if i == m-1 and j == n-1:
                return grid[i][j]

            down = dfs(i+1, j)
            right = dfs(i, j+1)
            return grid[i][j]+min(down, right)

        return dfs(0, 0)
