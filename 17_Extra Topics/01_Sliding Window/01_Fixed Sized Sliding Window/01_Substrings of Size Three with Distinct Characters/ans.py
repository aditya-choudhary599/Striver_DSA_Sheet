# Question Link : https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/

class Solution:

    def satisfy(self, s: str):
        mp = {}
        mp[s[0]] = 1

        if s[1] not in mp:
            mp[s[1]] = 1
        else:
            return False

        if s[2] not in mp:
            return True
        else:
            return False

    def countGoodSubstrings(self, s: str) -> int:
        left, right = 0, 2
        ans = 0
        while right < len(s):
            if self.satisfy(s[left:right+1:1]):
                ans += 1
            left += 1
            right += 1
        return ans
