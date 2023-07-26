# Question Link : https://www.codingninjas.com/studio/problems/children-sum-property_8357239?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0


class Node:
    def __init__(self, data=0, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


def isParentSum(root):
    if root is None or (root.left is None and root.right is None):
        return True

    small_ans = isParentSum(root.left) and isParentSum(root.right)
    if small_ans == False:
        return False

    if root.left is not None and root.right is not None:
        return root.data == root.left.data+root.right.data

    elif root.left is not None:
        return root.data == root.left.data

    else:
        return root.data == root.right.data
