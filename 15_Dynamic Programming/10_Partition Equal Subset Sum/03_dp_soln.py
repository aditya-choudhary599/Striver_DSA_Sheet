# Question Link : https://leetcode.com/problems/partition-equal-subset-sum/description/

from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)

        total_array_sum = sum(nums)

        if total_array_sum % 2 != 0:
            # this means the whole array sum is odd so it cannot be divided into two equal sum parts
            return False

        dp = [[0]*((total_array_sum//2)+1) for i in range(0, n, 1)]

        """ def helper(index:int,target:int) -> bool:
                if target==0:
                    return True
                if index<0:
                    return False

                if dp[index][target]!=-1:
                    if dp[index][target]==1:
                        return True
                    else:
                        return False
                
                if nums[index]<=target:
                    dp[index][target]=helper(index-1,target) or helper(index-1,target-nums[index])
                else:
                    dp[index][target]=helper(index-1,target)
                
                if dp[index][target]==1:
                        return True
                else:
                    return False """

        for i in range(0, n, 1):
            dp[i][0] = 1

        if nums[0] <= total_array_sum//2:
            dp[0][nums[0]] = 1

        for i in range(0, n, 1):
            for j in range(0, ((total_array_sum//2)+1), 1):
                if i-1 >= 0:
                    if nums[i] <= j:
                        dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i]]
                    else:
                        dp[i][j] = dp[i-1][j]

        return dp[n-1][(total_array_sum//2)]
