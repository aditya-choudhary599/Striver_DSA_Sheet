# Question Link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

from typing import List

class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        temp_sum = sum(cardPoints[0:k:1])
        left_window_size = k

        left_last_index = k-1
        right_last_index = len(cardPoints)-1

        ans = 0
        while left_window_size >= 0:
            # Iteration for previous window
            ans = max(ans, temp_sum)

            # Sliding the window
            temp_sum -= cardPoints[left_last_index]
            left_window_size -= 1
            left_last_index -= 1
            temp_sum += cardPoints[right_last_index]
            right_last_index -= 1

        return ans
