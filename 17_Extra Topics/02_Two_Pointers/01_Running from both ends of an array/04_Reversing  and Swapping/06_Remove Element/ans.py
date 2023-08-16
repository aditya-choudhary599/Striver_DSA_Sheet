""" Question Link : https://leetcode.com/problems/remove-element/description/ """


class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        insert_idx = -1

        for i in range(0, len(nums), 1):
            if nums[i] != val:
                insert_idx += 1
                nums[insert_idx] = nums[i]

        return insert_idx+1
