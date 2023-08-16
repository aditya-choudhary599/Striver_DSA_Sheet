# Question Link : https://leetcode.com/problems/trapping-rain-water/description/

# Solution Refrence : https://youtu.be/UZG3-vZlFM4

from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        left_to_right_max = [height[0]]
        for i in range(1, len(height), 1):
            left_to_right_max.append(max(left_to_right_max[-1], height[i]))

        right_to_left_max = [height[len(height)-1]]
        for i in range(len(height)-2, -1, -1):
            right_to_left_max.append(max(right_to_left_max[-1], height[i]))
        right_to_left_max.reverse()

        ans = 0
        for i in range(1, len(height)-1, 1):
            ans += min(left_to_right_max[i], right_to_left_max[i])-height[i]
        return ans
