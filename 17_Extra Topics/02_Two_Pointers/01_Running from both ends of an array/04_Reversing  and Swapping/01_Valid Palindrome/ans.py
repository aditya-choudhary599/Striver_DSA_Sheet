""" Question Link : https://leetcode.com/problems/valid-palindrome/description/ """


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.replace(' ', '')
        non_char = "!@#$%^&*()_+-={}[]|\:;\"'<>,.?/~`"

        for curr in non_char:
            s = s.replace(curr, '')

        s = s.lower()
        return s == s[::-1]
