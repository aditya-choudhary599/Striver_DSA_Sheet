# Question Link : https://leetcode.com/problems/minimum-window-substring/description/

# Variable size sliding window question

from typing import Lists
import sys


class Solution:

    def satisfy(self, window: dict, target: dict) -> bool:
        for key in target.keys():
            if key in window and window[key] >= target[key]:
                continue
            else:
                return False

        return True

    def minWindow(self, s: str, t: str) -> str:
        target = {}
        for char in t:
            if char in target:
                target[char] += 1
            else:
                target[char] = 1

        left, right = 0, 0
        window = {}
        comparator = sys.maxsize
        ans = ""

        while left <= right and right < len(s):
            if s[right] in window:
                window[s[right]] += 1
            else:
                window[s[right]] = 1

            while self.satisfy(window, target):
                if right-left+1 < comparator:
                    ans = s[left:right+1:1]
                    comparator = right-left+1
                window[s[left]] -= 1
                left += 1

            right += 1

        return ans
