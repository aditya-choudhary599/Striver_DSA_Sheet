# Question Link : https://practice.geeksforgeeks.org/problems/mirror-tree/1

class Node:
    def _init_(self, val):
        self.right = None
        self.data = val
        self.left = None


class Solution:
    # Function to convert a binary tree into its mirror tree.
    def mirror(self, root):
        # Code here
        if root is None or (root.left is None and root.right is None):
            return

        self.mirror(root.left)
        self.mirror(root.right)

        root.right, root.left = root.left, root.right

        return
