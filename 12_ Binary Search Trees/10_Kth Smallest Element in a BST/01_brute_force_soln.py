# Question Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def fill_inorder(self, root: TreeNode, temp: list) -> None:
        if root is None:
            return

        self.fill_inorder(root.left, temp)
        temp.append(root.val)
        self.fill_inorder(root.right, temp)

        return

    def kthSmallest(self, root: TreeNode, k: int) -> int:
        temp = []
        self.fill_inorder(root, temp)
        return temp[k-1]
