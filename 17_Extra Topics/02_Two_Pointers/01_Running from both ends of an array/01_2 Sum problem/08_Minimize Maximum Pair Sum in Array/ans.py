""" Question Link : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/ """

class Solution:
    def minPairSum(self, nums: list[int]) -> int:
        nums.sort()
        ans=0
        for i in range(0,len(nums)//2,1):
            ans=max(ans,nums[i]+nums[(i*-1)-1])
        return ans