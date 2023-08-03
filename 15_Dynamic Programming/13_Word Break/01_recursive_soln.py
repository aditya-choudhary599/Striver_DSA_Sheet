# Question Link : https://leetcode.com/problems/word-break/description/

from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        if s == "":
            return True

        curr = ""
        for i in range(0, len(s), 1):
            curr += s[i]
            if curr in wordDict and self.wordBreak(s[i+1:], wordDict):
                return True

        return False
