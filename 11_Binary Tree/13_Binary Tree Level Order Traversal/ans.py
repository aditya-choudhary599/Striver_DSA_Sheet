#  Question Link : https://leetcode.com/problems/binary-tree-level-order-traversal/description/

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: TreeNode) -> list:
        if root is None:
            return []

        q = []
        q.append(root)
        levels = []

        while len(q) != 0:
            n = len(q)
            temp = []
            for i in range(0, n, 1):
                front = q[0]
                temp.append(front.val)

                if front.left is not None:
                    q.append(front.left)

                if front.right is not None:
                    q.append(front.right)

                del q[0]

            levels.append(temp)

        return levels
