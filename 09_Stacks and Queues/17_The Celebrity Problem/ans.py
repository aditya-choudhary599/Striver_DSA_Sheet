# Question Link : https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution:

    # Function to find if there is a celebrity in the party or not.
    def celebrity(self, grid, n):

        original_grid = grid
        new_grid = list(map(list, zip(*grid)))

        for i in range(0, n, 1):
            new_grid[i][i] = 1

        temp_1 = [i for i, row in enumerate(new_grid) if all(
            element == 1 for element in row)]
        temp_2 = [i for i, row in enumerate(original_grid) if all(
            element == 0 for element in row)]

        common_celebrities = [
            element for element in temp_1 if element in temp_2]

        if len(common_celebrities) > 0:
            # Their is only one celebrity
            return common_celebrities[0]
        else:
            return -1
