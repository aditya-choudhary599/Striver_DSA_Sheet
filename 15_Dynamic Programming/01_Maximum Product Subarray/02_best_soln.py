# Question Link : https://leetcode.com/problems/maximum-product-subarray/description/

import sys
from typing import List

# This solution is inspired by the solution video that striver has uploaded in his A2Z series


class Solution:

    def split_list_at_zero(self, lst):
        sublists = []
        sublist = []
        for item in lst:
            if item == 0:
                if sublist:
                    sublists.append(sublist)
                    sublist = []
            else:
                sublist.append(item)

        if sublist:
            sublists.append(sublist)

        return sublists

    def maxProduct(self, arr: List[int]) -> int:
        ans = sys.maxsize*-1
        if 0 in arr:
            ans = 0

        new_nums = self.split_list_at_zero(arr)
        print(new_nums)

        for nums in new_nums:
            prod = 1
            ls = []*len(nums)
            for i in nums:
                prod *= i
                ans = max(prod, ans)
                ls.append(prod)

            for i in range(0, len(nums), 1):
                if nums[i] < 0:
                    left, right = sys.maxsize*-1, sys.maxsize*-1
                    if i-1 >= 0:
                        left = ls[i-1]
                    if i+1 < len(nums):
                        right = ls[len(nums)-1]//ls[i]
                    ans = max(left, right, ans)

        return ans
