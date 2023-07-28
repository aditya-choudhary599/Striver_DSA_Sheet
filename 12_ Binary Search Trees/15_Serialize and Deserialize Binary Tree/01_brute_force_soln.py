# Question Link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

import json


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        mp_1 = {}

        def f(root, mp_1, index):
            if root is None:
                return

            mp_1[index] = root.val

            f(root.left, mp_1, 2*index+1)
            f(root.right, mp_1, 2*index+2)

            return

        f(root, mp_1, 0)
        ans = json.dumps(mp_1)
        print(ans)
        return ans

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        my_dict = json.loads(data)
        new_dict = {int(key): value for key, value in my_dict.items()}

        table = {}
        for key in new_dict.keys():
            table[int(key)] = TreeNode(new_dict[key])

            if key != 0:
                if key % 2 != 0:
                    table[int((key-1)/2)].left = table[int(key)]
                else:
                    table[int((key-2)/2)].right = table[int(key)]

        return table.get(0)
