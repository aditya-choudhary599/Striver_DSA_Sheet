# Question Link : https://leetcode.com/problems/longest-common-subsequence/

class Solution:

    def f(self, i: int, j: int, text_1: str, text_2: str, dp: list) -> int:
        if i < 0 or j < 0:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]

        if text_1[i] == text_2[j]:
            dp[i][j] = 1+self.f(i-1, j-1, text_1, text_2, dp)
            return dp[i][j]
        else:
            dp[i][j] = max(self.f(i-1, j, text_1, text_2, dp),
                           self.f(i, j-1, text_1, text_2, dp))
            return dp[i][j]

    def longestCommonSubsequence(self, text_1: str, text_2: str) -> int:
        dp = [[-1]*len(text_2) for i in range(0, len(text_1), 1)]
        return self.f(len(text_1)-1, len(text_2)-1, text_1, text_2, dp)
