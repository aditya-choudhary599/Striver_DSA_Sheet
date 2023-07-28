# Question Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is None:
            return None

        if root.val == p.val or root.val == q.val:
            return root

        lcall = self.lowestCommonAncestor(root.left, p, q)
        rcall = self.lowestCommonAncestor(root.right, p, q)

        if (lcall == p and rcall == q) or (lcall == q and rcall == p):
            return root

        if lcall is not None:
            return lcall

        else:
            return rcall