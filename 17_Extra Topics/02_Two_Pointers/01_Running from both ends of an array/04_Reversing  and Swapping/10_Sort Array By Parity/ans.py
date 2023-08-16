# Question Link : https://leetcode.com/problems/sort-array-by-parity/description/

class Solution:
    def sortArrayByParity(self, nums: list[int]) -> list[int]:
        idx = -1

        for i in range(0, len(nums), 1):
            if nums[i] % 2 == 0:
                idx += 1
                nums[i], nums[idx] = nums[idx], nums[i]

        return nums
