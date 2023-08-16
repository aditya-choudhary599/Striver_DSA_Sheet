# Question Link : https://leetcode.com/problems/reverse-only-letters/description/

class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        s_list = list(s)
        left = 0

        while left < len(s_list) and not s[left].isalpha():
            left += 1

        if left == len(s_list):
            # As there are no alphabets in the string
            return s

        right = len(s_list) - 1

        while right >= 0 and not s[right].isalpha():
            right -= 1

        while left <= right:
            s_list[left], s_list[right] = s_list[right], s_list[left]

            left += 1
            right -= 1

            while left < len(s_list) and not s[left].isalpha():
                left += 1

            while right >= 0 and not s[right].isalpha():
                right -= 1

        return ''.join(s_list)