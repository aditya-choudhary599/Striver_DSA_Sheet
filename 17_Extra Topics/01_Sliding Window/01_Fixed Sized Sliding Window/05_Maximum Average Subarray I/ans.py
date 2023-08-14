# Question Link : https://leetcode.com/problems/maximum-average-subarray-i/description/

from typing import List
import sys

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        prefix_sum = 0

        for i in range(0, k, 1):
            prefix_sum += nums[i]

        ans = sys.maxsize*-1

        for i in range(k, len(nums), 1):
            # Calculate for previous window first
            ans = max(ans, prefix_sum/k)

            # Move the window
            prefix_sum -= nums[i-k]
            prefix_sum += nums[i]

        # For last window
        ans = max(ans, prefix_sum/k)

        return ans
