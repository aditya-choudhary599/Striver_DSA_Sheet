# Question Link : https://leetcode.com/problems/partition-equal-subset-sum/description/

from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        total_array_sum = sum(nums)

        if total_array_sum % 2 != 0:
            # this means the whole array sum is odd so it cannot be divided into two equal sum parts
            return False

        def helper(index: int, target: int) -> bool:
            if target == 0:
                return True
            if index < 0:
                return False

            if nums[index] <= target:
                return helper(index-1, target) or helper(index-1, target-nums[index])
            else:
                return helper(index-1, target)

        return helper(n-1, total_array_sum//2)
