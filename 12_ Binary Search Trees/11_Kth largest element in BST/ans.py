# Question Link : https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

# return the Kth largest element in the given BST rooted at 'root'


class Solution:
    def __init__(self):
        self.cnt = 0
        self.ans = -1

    def f(self, root, k: int) -> None:
        if root is None:
            return

        if self.cnt == k:
            self.ans = root.data
            return

        self.f(root.left, k)
        if self.ans != -1:
            return
        else:
            self.cnt += 1
            if self.cnt == k:
                self.ans = root.data
                return
            else:
                self.f(root.right, k)

    def kthSmallest(self, root, k) -> int:
        self.f(root, k)
        return self.ans

    def number_of_nodes(self, root) -> int:
        if root is None:
            return 0
        return 1+self.number_of_nodes(root.left)+self.number_of_nodes(root.right)

    def kthLargest(self, root, k):
        # your code here
        n = self.number_of_nodes(root)
        return self.kthSmallest(root, n-k+1)
