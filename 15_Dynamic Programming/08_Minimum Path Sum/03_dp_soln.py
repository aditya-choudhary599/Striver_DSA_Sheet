# Question Link : https://leetcode.com/problems/minimum-path-sum/

from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        dp = [[0]*n for i in range(0, m, 1)]

        """ def dfs(i:int,j:int):
                if i>=m or j>=n:
                    return 1e9
                
                if i==m-1 and j==n-1:
                    return grid[i][j]

                if dp[i][j]!=-1:
                    return dp[i][j]

                down=dfs(i+1,j)
                right=dfs(i,j+1)
                dp[i][j]=grid[i][j]+min(down,right)
                return dp[i][j] """

        dp[m-1][n-1] = grid[m-1][n-1]

        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if i == m-1 and j == n-1:
                    continue
                down, right = 1e9, 1e9
                if i+1 < m:
                    down = dp[i+1][j]
                if j+1 < n:
                    right = dp[i][j+1]
                dp[i][j] = grid[i][j]+min(down, right)

        return dp[0][0]
