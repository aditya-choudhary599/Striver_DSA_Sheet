# Question Link : https://leetcode.com/problems/word-break/description/

from typing import List


class Solution:

    def __init__(self):
        self.dp = {}

    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        if s == "":
            return True

        if s in self.dp:
            return self.dp[s]

        curr = ""
        for i in range(0, len(s), 1):
            curr += s[i]
            if curr in wordDict and self.wordBreak(s[i+1:], wordDict):
                self.dp[s] = True
                return True

        self.dp[s] = False
        return False
