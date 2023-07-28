# Question Link : https://www.codingninjas.com/studio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def floorInBST(root, x) -> int:
    if root is None:
        return -1

    if root.data == x:
        return x

    elif root.data < x:
        return max(root.data, floorInBST(root.right, x))

    else:
        return floorInBST(root.left, x)
