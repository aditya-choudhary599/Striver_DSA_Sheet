# Question Link : https://leetcode.com/problems/minimum-size-subarray-sum/description/

# Variable sliding window approach

from typing import List
import sys

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans=sys.maxsize
        left,right=0,0
        temp_sum=0

        while left<=right and right<len(nums):
            temp_sum+=nums[right]
            
            while temp_sum>=target:
                ans=min(right-left+1,ans)
                temp_sum-=nums[left]
                left+=1
            
            right+=1
        
        if ans==sys.maxsize:
            return 0
        else:
            return ans