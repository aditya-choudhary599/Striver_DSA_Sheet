# Question Link : https://www.codingninjas.com/studio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0

import sys

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def f(root, x):
    if root is None:
        return sys.maxsize

    if root.data == x:
        return x

    elif root.data > x:
        return min(root.data, f(root.left, x))

    else:
        return f(root.right, x)


def findCeil(root, x):
    ans = f(root, x)
    if ans == sys.maxsize:
        return -1
    else:
        return ans
