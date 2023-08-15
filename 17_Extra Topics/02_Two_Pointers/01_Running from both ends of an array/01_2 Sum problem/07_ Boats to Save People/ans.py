""" Question Link : https://leetcode.com/problems/boats-to-save-people/description/ """


class Solution:
    def numRescueBoats(self, nums: list[int], limit: int) -> int:
        nums.sort()
        left = 0
        right = len(nums)-1
        ans = 0

        while left <= right:
            if nums[left]+nums[right] <= limit:
                left += 1
                right -= 1
                ans += 1
            else:
                ans += 1
                right -= 1

        return ans
