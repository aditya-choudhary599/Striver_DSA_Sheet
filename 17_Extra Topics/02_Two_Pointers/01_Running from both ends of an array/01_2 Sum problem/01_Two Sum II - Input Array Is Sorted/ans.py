# Question Link : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        left = 0
        right = len(nums)-1

        while left < right:
            if nums[left]+nums[right] == target:
                return [left+1, right+1]
            elif nums[left]+nums[right] < target:
                left += 1
            else:
                right -= 1

        return [-1, -1]
