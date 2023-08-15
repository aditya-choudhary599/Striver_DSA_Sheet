# Question Link : https://leetcode.com/problems/maximum-erasure-value/description/

class Solution:
    def maximumUniqueSubarray(self, nums: list[int]) -> int:
        left = 0
        right = 0
        temp_sum = 0
        helper = []
        ans = 0

        while left <= right and right < len(nums):

            while nums[right] in helper:
                temp_sum -= nums[left]
                helper.remove(nums[left])
                left += 1

            temp_sum += nums[right]
            helper.append(nums[right])
            ans = max(ans, temp_sum)
            right += 1

        return ans
