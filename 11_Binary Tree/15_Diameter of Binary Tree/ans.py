# Question Link : https://leetcode.com/problems/diameter-of-binary-tree/description/


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def f(self, root: TreeNode) -> int:
        if root is None:
            return 0
        l = self.f(root.left)
        r = self.f(root.right)
        self.maxi = max(self.maxi, l+r)
        return 1+max(l, r)

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.maxi = 0
        self.f(root)
        return self.maxi
