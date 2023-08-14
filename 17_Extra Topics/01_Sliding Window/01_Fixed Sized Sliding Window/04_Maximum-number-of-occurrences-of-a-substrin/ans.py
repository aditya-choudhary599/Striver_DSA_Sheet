
# Question Link : https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/

# Here their is no use of maxSize.

class Solution:

    def satisfy(self, s: str, k: int):
        char_count = {}
        for char in s:
            char_count[char] = char_count.get(char, 0) + 1
            if len(char_count) > k:
                return False
        return True

    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        substring_freq = {}
        ans = 0

        size = minSize
        left = 0
        right = size - 1

        char_count = {}

        # Initialize character count for the initial substring
        for i in range(left, right + 1):
            char_count[s[i]] = char_count.get(s[i], 0) + 1

        while right < len(s):
            if self.satisfy(s[left:right + 1], maxLetters):
                substring = s[left:right + 1]
                substring_freq[substring] = substring_freq.get(
                    substring, 0) + 1
                ans = max(ans, substring_freq[substring])

            # Slide the window
            char_count[s[left]] -= 1
            if char_count[s[left]] == 0:
                del char_count[s[left]]
            left += 1
            right += 1
            if right < len(s):
                char_count[s[right]] = char_count.get(s[right], 0) + 1

        return ans
