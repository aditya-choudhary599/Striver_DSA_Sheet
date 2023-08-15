""" Question Link : https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/ """


class Solution:
    def numSubseq(self, nums: list[int], target: int) -> int:
        n, mod = len(nums), 10 ** 9 + 7
        nums.sort()

        answer = 0
        left, right = 0, n - 1

        while left <= right:
            if nums[left] + nums[right] <= target:
                answer = (answer + pow(2, right - left, mod)) % mod
                left += 1
            else:
                right -= 1

        return answer
