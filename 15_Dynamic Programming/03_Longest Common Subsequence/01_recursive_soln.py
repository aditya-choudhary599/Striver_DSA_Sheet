# Question Link : https://leetcode.com/problems/longest-common-subsequence/

class Solution:

    def f(self, i: int, j: int, text_1: str, text_2: str) -> int:
        if i < 0 or j < 0:
            return 0

        if text_1[i] == text_2[j]:
            return 1+self.f(i-1, j-1, text_1, text_2)
        else:
            return max(self.f(i-1, j, text_1, text_2), self.f(i, j-1, text_1, text_2))

    def longestCommonSubsequence(self, text_1: str, text_2: str) -> int:
        return self.f(len(text_1)-1, len(text_2)-1, text_1, text_2)
