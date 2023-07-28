# Question Link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if len(nums)==0:
            return None
        if len(nums)==1:
            ans=TreeNode(nums[0])
            return ans
        
        new_root=TreeNode(nums[len(nums)//2])

        new_root.left=self.sortedArrayToBST(nums[0:len(nums)//2])
        new_root.right=self.sortedArrayToBST(nums[len(nums)//2+1:])

        return new_root