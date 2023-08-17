""" Question Link : https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/ """


class Solution:
    def minimumLength(self, s: str) -> int:
        ans = len(s)
        left, right = 0, len(s)-1

        while left < right:
            if s[left] == s[right]:

                left += 1
                while left < right and s[left] == s[left-1]:
                    left += 1

                right -= 1
                while left < right and s[right] == s[right+1]:
                    right -= 1

                ans = min(ans, right-left+1)

            else:
                return ans

        return ans
