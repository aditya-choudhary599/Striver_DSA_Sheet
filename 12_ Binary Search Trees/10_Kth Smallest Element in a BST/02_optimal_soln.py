# Question Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

# This approach was exaplined by striver in his solution video of this problem

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.cnt = 0
        self.ans = -1

    def f(self, root: TreeNode, k: int) -> None:
        if root is None:
            return

        if self.cnt == k:
            self.ans = root.val
            return

        self.f(root.left, k)
        if self.ans != -1:
            return
        else:
            self.cnt += 1
            if self.cnt == k:
                self.ans = root.val
                return
            else:
                self.f(root.right, k)

    def kthSmallest(self, root: TreeNode, k: int) -> int:
        self.f(root, k)
        return self.ans
