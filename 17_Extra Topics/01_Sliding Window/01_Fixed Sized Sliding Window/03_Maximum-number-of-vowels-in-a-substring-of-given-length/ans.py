# Question Link : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        left, right = 0, k - 1

        vowels = set('aeiou')
        curr_substring = s[left:right+1]
        curr_count = sum(1 for char in curr_substring if char in vowels)

        max_count = curr_count

        while right < len(s) - 1:
            if s[left] in vowels:
                curr_count -= 1
            left += 1
            right += 1
            if s[right] in vowels:
                curr_count += 1
            max_count = max(max_count, curr_count)

        return max_count
