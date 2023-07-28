# Question Link : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.mp = []

    def findTarget(self, root: TreeNode, k: int) -> bool:
        if root is None:
            return False

        if k-root.val in self.mp:
            return True

        self.mp.append(root.val)

        return self.findTarget(root.left, k) or self.findTarget(root.right, k)
