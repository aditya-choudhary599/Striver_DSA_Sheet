""" Question Link : https://leetcode.com/problems/pancake-sorting/description/ """

""" Imp condition given in question : All integers in arr are unique (i.e. arr is a permutation of the integers from 1 to arr.length). """

from typing import List

class Solution:
    def pancakeSort(self, nums: List[int]) -> List[int]:
        target = nums.copy()
        target.sort()

        ans = []

        index = len(nums)-1

        while index >= 0:
            if target[index] == nums[index]:
                index -= 1
                continue

            helper = nums.index(target[index])

            if helper != 0:
                ans.append(helper+1)
                nums = nums[helper::-1]+nums[helper+1::1]

            nums = nums[index::-1]+nums[index+1::1]
            ans.append(index+1)

            index -= 1

        return ans
