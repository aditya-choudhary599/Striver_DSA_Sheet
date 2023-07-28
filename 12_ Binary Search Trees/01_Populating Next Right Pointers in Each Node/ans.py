# Question Link : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/


# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root: Node) -> Node:
        if root is None:
            return None

        q = []
        q.append(root)
        levels = []

        while len(q) != 0:
            n = len(q)
            temp = []
            for i in range(0, n, 1):
                front = q[0]
                temp.append(front)

                if front.left is not None:
                    q.append(front.left)

                if front.right is not None:
                    q.append(front.right)

                del q[0]

            levels.append(temp)

        for level in levels:
            for i in range(0, len(level)-1, 1):
                level[i].next = level[i+1]
            level[len(level)-1].next = None

        return root
