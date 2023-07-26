# Question Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(inorder) == 0:
            return None
        if len(inorder) == 1:
            ans = TreeNode(inorder[0])
            return ans

        left_inorder = []
        right_inorder = []

        new_root = TreeNode(preorder[0])

        helper = False
        for i in range(0, len(inorder), 1):
            if inorder[i] != new_root.val and helper == False:
                left_inorder.append(inorder[i])

            elif inorder[i] != new_root.val and helper == True:
                right_inorder.append(inorder[i])

            elif inorder[i] == new_root.val:
                helper = True

        left_preorder = [item for item in preorder if item in left_inorder]
        right_preorder = [item for item in preorder if item in right_inorder]

        new_root.left = self.buildTree(left_preorder, left_inorder)
        new_root.right = self.buildTree(right_preorder, right_inorder)

        return new_root
