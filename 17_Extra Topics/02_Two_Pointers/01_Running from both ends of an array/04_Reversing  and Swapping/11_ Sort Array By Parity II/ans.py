""" Question Link : https://leetcode.com/problems/sort-array-by-parity-ii/description/ 
    Solution Refrence Link : https://www.youtube.com/watch?v=pHRFRZGbK5s """

from typing import List


class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        i = 0
        j = 1

        while i < len(nums) and j < len(nums):
            while i < len(nums) and nums[i] % 2 == 0:
                i += 2

            while j < len(nums) and nums[j] % 2 != 0:
                j += 2

            # Swapping the disorderd elements
            if i < len(nums) and j < len(nums):
                nums[i], nums[j] = nums[j], nums[i]
                i += 2
                j += 2

        return nums
