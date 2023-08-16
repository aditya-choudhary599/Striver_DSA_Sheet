# Question Link : https://leetcode.com/problems/sort-colors/description/

class Solution:
    def sortColors(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        one_ptr = -1
        two_ptr = len(nums)

        i = 0

        while i < two_ptr:
            if nums[i] == 0:
                one_ptr += 1
                nums[one_ptr], nums[i] = nums[i], nums[one_ptr]
                i += 1

            elif nums[i] == 1:
                i += 1

            else:
                two_ptr -= 1
                nums[two_ptr], nums[i] = nums[i], nums[two_ptr]

        return
