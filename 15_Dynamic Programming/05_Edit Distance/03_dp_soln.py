# Question Link : https://leetcode.com/problems/edit-distance/description/

import sys


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
        dp = [[sys.maxsize]*(len(word_2)+1)
              for _ in range(0, len(word_1)+1, 1)]

        for i in range(0, len(word_1)+1, 1):
            dp[i][0] = i

        for j in range(0, len(word_2)+1, 1):
            dp[0][j] = j

        for i in range(1, len(word_1)+1, 1):
            for j in range(1, len(word_2)+1, 1):
                if word_1[i-1] == word_2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = 1+min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])

        return dp[len(word_1)][len(word_2)]
