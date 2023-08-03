# Question Link : https://leetcode.com/problems/minimum-path-sum/

from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        dp = [[-1]*n for i in range(0, m, 1)]

        def dfs(i: int, j: int):
            if i >= m or j >= n:
                return 1e9

            if i == m-1 and j == n-1:
                return grid[i][j]

            if dp[i][j] != -1:
                return dp[i][j]

            down = dfs(i+1, j)
            right = dfs(i, j+1)
            dp[i][j] = grid[i][j]+min(down, right)
            return dp[i][j]

        return dfs(0, 0)
