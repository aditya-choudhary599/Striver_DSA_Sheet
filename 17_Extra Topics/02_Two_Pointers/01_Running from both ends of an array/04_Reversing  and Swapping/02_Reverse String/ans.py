""" Question Link : https://leetcode.com/problems/reverse-string/description/ """


class Solution:
    def reverseString(self, ls: list[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        left = 0
        right = len(ls)-1

        while left <= right:
            ls[left], ls[right] = ls[right], ls[left]
            left += 1
            right -= 1

        return
