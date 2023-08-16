""" Question Link : https://leetcode.com/problems/squares-of-a-sorted-array/description/ """


class Solution:
    def sortedSquares(self, nums: list[int]) -> list[int]:
        ans = []
        left = 0
        right = len(nums)-1

        while left <= right:
            left_num_sq = nums[left]**2
            right_num_sq = nums[right]**2

            if left_num_sq >= right_num_sq:
                ans = [left_num_sq]+ans
                left += 1

            else:
                ans = [right_num_sq]+ans
                right -= 1

        return ans
