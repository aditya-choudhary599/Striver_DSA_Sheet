# Question Link : https://leetcode.com/problems/k-radius-subarray-averages/description/

from typing import List
class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        if k > len(nums)//2:
            return [-1]*len(nums)

        prefix_ans = [-1]*k
        suffix_ans = [-1]*k

        middle_ans = []

        curr_sum = sum(nums[0:2*k+1:1])

        left, right = 0, 2*k
        while right < len(nums):
            middle_ans.append(curr_sum//(2*k+1))

            # Sliding window
            curr_sum -= nums[left]
            left += 1
            right += 1
            if right < len(nums):
                curr_sum += nums[right]

        op = prefix_ans+middle_ans+suffix_ans

        return op
