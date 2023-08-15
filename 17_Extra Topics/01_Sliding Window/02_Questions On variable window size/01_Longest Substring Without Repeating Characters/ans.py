""" Question Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/ """

from collections import defaultdict


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_freq = defaultdict(int)
        ans = 0
        left = 0
        right = 0

        while right < len(s):
            char_freq[s[right]] += 1

            while char_freq[s[right]] > 1:
                char_freq[s[left]] -= 1
                left += 1

            ans = max(ans, right - left + 1)
            right += 1

        return ans
