# Question Link : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Trio:
    def __init__(self):
        self.low_bound = 0
        self.high_bound = 0
        self.is_BST = False
        self.sum = 0


class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        def f(root, maxi):
            if not root:
                return Trio()

            curr = Trio()

            if root.left and root.right:
                left = f(root.left, maxi)
                right = f(root.right, maxi)

                if left.is_BST and right.is_BST and left.high_bound < root.val < right.low_bound:
                    maxi[0] = max(maxi[0], left.sum + right.sum + root.val)
                    curr.low_bound = left.low_bound
                    curr.high_bound = right.high_bound
                    curr.is_BST = True
                    curr.sum = left.sum + right.sum + root.val
                    return curr
                else:
                    curr.low_bound = left.low_bound
                    curr.high_bound = right.high_bound
                    curr.is_BST = False
                    curr.sum = 0
                    return curr

            elif not root.left and root.right:
                right = f(root.right, maxi)
                if right.is_BST and root.val < right.low_bound:
                    maxi[0] = max(maxi[0], right.sum + root.val)
                    curr.low_bound = root.val
                    curr.high_bound = right.high_bound
                    curr.is_BST = True
                    curr.sum = right.sum + root.val
                    return curr
                else:
                    curr.low_bound = root.val
                    curr.high_bound = right.high_bound
                    curr.is_BST = False
                    curr.sum = 0
                    return curr

            elif root.left and not root.right:
                left = f(root.left, maxi)
                if left.is_BST and root.val > left.high_bound:
                    maxi[0] = max(maxi[0], left.sum + root.val)
                    curr.low_bound = left.low_bound
                    curr.high_bound = root.val
                    curr.is_BST = True
                    curr.sum = left.sum + root.val
                    return curr
                else:
                    curr.low_bound = left.low_bound
                    curr.high_bound = root.val
                    curr.is_BST = False
                    curr.sum = 0
                    return curr

            else:
                maxi[0] = max(maxi[0], root.val)
                curr.low_bound = root.val
                curr.high_bound = root.val
                curr.is_BST = True
                curr.sum = root.val
                return curr

        maxi = [0]
        f(root, maxi)
        return maxi[0]
