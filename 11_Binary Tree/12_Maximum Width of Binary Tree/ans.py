# Question Link : https://leetcode.com/problems/maximum-width-of-binary-tree/description/

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.mp = {}

    def fill(self,root:TreeNode,index:int,level:int) -> None:
        if root is None:
            return

        if level not in self.mp:
            self.mp[level]=[index]
        else:
            self.mp[level].append(index)

        self.fill(root.left,2*index+1,level+1)
        self.fill(root.right,2*index+2,level+1)
        return

    def widthOfBinaryTree(self, root: TreeNode) -> int:
        self.fill(root,0,0)
        ans=0
        for value in self.mp.values():
            ans=max(ans,max(value)-min(value)+1)
        
        return ans

        