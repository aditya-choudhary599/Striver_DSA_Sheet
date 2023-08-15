# Question Link : https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution:
    def numberOfSubarrays(self, nums: list[int], k: int) -> int:
        right, left = 0, 0
        ans = 0
        odd_cnt = 0
        ans = 0
        cur_sub_cnt = 0

        for right in range(len(nums)):

            if nums[right] % 2 == 1:
                odd_cnt += 1
                cur_sub_cnt = 0

            while odd_cnt == k:
                if nums[left] % 2 == 1:
                    odd_cnt -= 1
                cur_sub_cnt += 1
                left += 1

            ans += cur_sub_cnt

        return ans
