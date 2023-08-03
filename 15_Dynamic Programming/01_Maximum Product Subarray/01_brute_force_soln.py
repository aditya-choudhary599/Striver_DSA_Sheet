# Question Link : https://leetcode.com/problems/maximum-product-subarray/description/

from typing import List
import sys


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = sys.maxsize*-1
        for i in range(0, len(nums), 1):
            product = 1
            for j in range(i, len(nums), 1):
                product *= nums[j]
                ans = max(ans, product)
        return ans
