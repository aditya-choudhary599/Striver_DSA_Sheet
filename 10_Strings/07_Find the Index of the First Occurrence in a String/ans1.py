# Question Link : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution:
    def strStr(self, s1: str, s2: str) -> int:
        m = len(s1)
        n = len(s2)

        for i in range(0, m-n+1, 1):
            if s1[i:n+i] == s2:
                return i

        return -1
