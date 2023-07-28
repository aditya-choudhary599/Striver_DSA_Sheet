# Question Link : https://leetcode.com/problems/binary-search-tree-iterator/description/

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BSTIterator:
    def __init__(self, root: TreeNode):
        self.arr = []
        self.inorder(root)

    def inorder(self, root: TreeNode):
        if root is None:
            return

        self.inorder(root.left)
        self.arr.append(root.val)
        self.inorder(root.right)
        return

    def next(self) -> int:
        ans = self.arr[0]
        del self.arr[0]
        return ans

    def hasNext(self) -> bool:
        return len(self.arr) != 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
