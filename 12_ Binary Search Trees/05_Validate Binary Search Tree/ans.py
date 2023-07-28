# Question Link : https://leetcode.com/problems/validate-binary-search-tree/description/

import sys


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def f(self, root: TreeNode, lower_b: int, upper_b: int) -> bool:
        if root is None:
            return True

        if root.val > lower_b and root.val < upper_b:
            return self.f(root.left, lower_b, root.val) and self.f(root.right, root.val, upper_b)

        else:
            return False

    def isValidBST(self, root:TreeNode) -> bool:
        return self.f(root, -1*sys.maxsize, sys.maxsize)
