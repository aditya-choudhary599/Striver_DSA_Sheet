# Question Link : https://leetcode.com/problems/symmetric-tree/description/

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def f(self, root_1: TreeNode, root_2: TreeNode) -> bool:
        if (root_1 is None and root_2 is not None) or (root_1 is not None and root_2 is None):
            return False

        if (root_1 is None and root_2 is None):
            return True

        if root_1.val == root_2.val:
            return self.f(root_1.left, root_2.right) and self.f(root_1.right, root_2.left)

        else:
            return False

    def isSymmetric(self, root: TreeNode) -> bool:
        return self.f(root, root)
