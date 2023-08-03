# Question Link : https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

class Solution:
    def maxSumIS(self, nums, n):
        ans = [0]*n
        ans[0] = nums[0]
        op = nums[0]

        for i in range(1, n, 1):
            temp = 0
            for j in range(0, i, 1):
                if nums[j] < nums[i]:
                    temp = max(ans[j], temp)
            ans[i] = temp+nums[i]
            op = max(op, ans[i])

        return op
