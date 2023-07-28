# Question Link : https://www.codingninjas.com/studio/problems/893049?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


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


def get_inorder(root, temp: list):
    if root is None:
        return

    get_inorder(root.left, temp)
    temp.append(root.data)
    get_inorder(root.right, temp)

    return


def predecessorSuccessor(root, key):
    temp = []
    get_inorder(root, temp)
    ans = []
    for i in range(0, len(temp), 1):
        if temp[i] == key:
            if i-1 >= 0:
                ans.append(temp[i-1])
            else:
                ans.append(-1)

            if i+1 < len(temp):
                ans.append(temp[i+1])
            else:
                ans.append(-1)

    return ans
