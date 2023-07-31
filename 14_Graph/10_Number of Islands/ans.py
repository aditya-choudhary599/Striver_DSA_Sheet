# Question Link : https://leetcode.com/problems/number-of-islands/description/


class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        m = len(grid)
        n = len(grid[0])

        vis = [[False]*n for i in range(0, m, 1)]
        ans = 0

        def dfs(i: int, j: int) -> None:
            vis[i][j] = True

            # Checking right:
            if j+1 < n and grid[i][j+1] == '1' and vis[i][j+1] == False:
                dfs(i, j+1)

            # Checking left:
            if j-1 >= 0 and grid[i][j-1] == '1' and vis[i][j-1] == False:
                dfs(i, j-1)

            # Checking down:
            if i+1 < m and grid[i+1][j] == '1' and vis[i+1][j] == False:
                dfs(i+1, j)

            # Checking up:
            if i-1 >= 0 and grid[i-1][j] == '1' and vis[i-1][j] == False:
                dfs(i-1, j)

            return

        for i in range(0, m, 1):
            for j in range(0, n, 1):
                if grid[i][j] == '1' and vis[i][j] == False:
                    dfs(i, j)
                    ans += 1

        return ans
