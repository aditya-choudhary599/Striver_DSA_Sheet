# Question Link : https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

from typing import List

class Solution:

    def satisfy(self, window: dict, target: dict):
        for key in target.keys():
            if key in window and window[key] == target[key]:
                continue
            else:
                return False

        return True

    def findAnagrams(self, s: str, p: str) -> List[int]:
        target = {}
        for char in p:
            if char in target:
                target[char] += 1
            else:
                target[char] = 1

        window = {}
        for char in s[0:len(p):1]:
            if char in window:
                window[char] += 1
            else:
                window[char] = 1

        left, right = 0, len(p)-1
        ans = []
        for char in s[len(p)::1]:
            # Checking for previous window
            if self.satisfy(window, target):
                ans.append(left)

            # Slide the window
            window[s[left]] -= 1
            left += 1
            right += 1
            if char in window:
                window[char] += 1
            else:
                window[char] = 1

        # Checking for last window
        if self.satisfy(window, target):
            ans.append(left)

        return ans
