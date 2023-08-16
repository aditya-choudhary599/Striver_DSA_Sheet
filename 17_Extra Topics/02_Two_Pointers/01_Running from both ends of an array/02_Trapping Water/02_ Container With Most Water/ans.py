""" Question Link : https://leetcode.com/problems/container-with-most-water/ """

class Solution:
    def maxArea(self, nums: list[int]) -> int:
        left = 0
        right = len(nums)-1
        ans = 0

        while left < right:
            if nums[left] <= nums[right]:
                ans = max(ans, nums[left]*(right-left))
                left += 1
            else:
                ans = max(ans, nums[right]*(right-left))
                right -= 1

        return ans
