# Question Link : https://leetcode.com/problems/edit-distance/description/

class Solution:

    def f(self, i: int, j: int, word_1: str, word_2: str, dp: list) -> int:
        if j < 0:
            # we will perform the multiple delete operation
            return i+1
        if i < 0:
            # we will perform the multiple insertion operation
            return j+1

        if dp[i][j] != -1:
            return dp[i][j]

        if word_1[i] == word_2[j]:
            dp[i][j] = self.f(i-1, j-1, word_1, word_2, dp)
        else:
            replace_operation = 1+self.f(i-1, j-1, word_1, word_2, dp)
            delete_operation = 1+self.f(i-1, j, word_1, word_2, dp)
            insert_operation = 1+self.f(i, j-1, word_1, word_2, dp)

            dp[i][j] = min(replace_operation,
                           delete_operation, insert_operation)

        return dp[i][j]

    def minDistance(self, word_1: str, word_2: str) -> int:
        dp = [[-1]*len(word_2) for _ in range(0, len(word_1), 1)]
        return self.f(len(word_1)-1, len(word_2)-1, word_1, word_2, dp)
