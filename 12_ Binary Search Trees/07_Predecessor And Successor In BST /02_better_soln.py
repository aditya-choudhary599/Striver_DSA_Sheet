# Question Link : https://www.codingninjas.com/studio/problems/893049?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

import sys

class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def __del__(self):
        if self.left:
            del self.left
        if self.right:
            del self.right


def f(root, key: int, ans: list) -> None:
    if root is None:
        return

    if root.data < key:
        ans[0] = max(ans[0], root.data)
    elif root.data > key:
        ans[1] = min(ans[1], root.data)

    f(root.left, key, ans)
    f(root.right, key, ans)


def predecessorSuccessor(root, key):
    ans = [-1 * sys.maxsize, 1 * sys.maxsize]
    f(root, key, ans)

    if ans[0] == -1*sys.maxsize:
        ans[0] = -1
    if ans[1] == 1*sys.maxsize:
        ans[1] = -1

    return ans
