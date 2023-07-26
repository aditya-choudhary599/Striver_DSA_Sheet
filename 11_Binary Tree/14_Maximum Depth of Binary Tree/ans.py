# Question Link : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0

        return 1+max(self.maxDepth(root.left), self.maxDepth(root.right))