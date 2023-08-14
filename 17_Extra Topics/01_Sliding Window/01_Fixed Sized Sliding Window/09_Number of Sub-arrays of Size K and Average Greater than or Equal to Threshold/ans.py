""" Question Link : https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/ """

from typing import List

class Solution:
    def numOfSubarrays(self, nums: List[int], k: int, threshold: int) -> int:
        prefix_sum = 0

        for i in range(0, k, 1):
            prefix_sum += nums[i]

        ans = 0

        for i in range(k, len(nums), 1):
            # Calculate for previous window first
            if prefix_sum/k >= threshold:
                ans += 1

            # Move the window
            prefix_sum -= nums[i-k]
            prefix_sum += nums[i]

        # For last window
        if prefix_sum/k >= threshold:
            ans += 1

        return ans
