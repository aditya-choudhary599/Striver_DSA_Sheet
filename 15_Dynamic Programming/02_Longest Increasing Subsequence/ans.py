# Question Link : https://leetcode.com/problems/longest-increasing-subsequence/

from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) is 1:
            return 1
        ans = [0]*len(nums)
        ans[0] = 1
        op = 0

        for i in range(1, len(nums), 1):
            temp = 0
            for j in range(0, i, 1):
                if nums[j] < nums[i]:
                    temp = max(ans[j], temp)
            ans[i] = temp+1
            op = max(op, ans[i])

        return op
