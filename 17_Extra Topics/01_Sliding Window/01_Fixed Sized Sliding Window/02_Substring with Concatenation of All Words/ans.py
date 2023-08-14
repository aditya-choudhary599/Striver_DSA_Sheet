# Question Link : https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

from typing import List


class Solution:

    def satisfy(self, curr: str, words: List[str]) -> bool:
        k = len(words[0])
        curr_list = [curr[i:i+k:1] for i in range(0, len(curr), k)]

        mp_1 = {}
        for key in words:
            if key in mp_1:
                mp_1[key] += 1
            else:
                mp_1[key] = 1

        mp_2 = {}
        for key in curr_list:
            if key in mp_2:
                mp_2[key] += 1
            else:
                mp_2[key] = 1

        for key in mp_1.keys():
            if key in mp_2 and mp_2[key] == mp_1[key]:
                continue
            else:
                return False

        return True

    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        left, right = 0, (len(words)*len(words[0]))-1
        ans = []
        while right < len(s):
            if self.satisfy(s[left:right+1:1], words):
                ans.append(left)
            left += 1
            right += 1

        return ans
