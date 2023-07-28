# Question Link : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if len(preorder) == 0:
            return None
        if len(preorder) == 1:
            ans = TreeNode(preorder[0])
            return ans

        root = TreeNode(preorder[0])
        left_preorder = [item for item in preorder if item < preorder[0]]
        right_preorder = [item for item in preorder if item > preorder[0]]

        root.left = self.bstFromPreorder(left_preorder)
        root.right = self.bstFromPreorder(right_preorder)

        return root
