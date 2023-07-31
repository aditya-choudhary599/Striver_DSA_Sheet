# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None

        mp = {}
        mp[node] = Node(node.val)

        vis = {}
        q = [node]

        while q:
            front = q.pop(0)
            if front not in vis:
                vis[front] = True

                for neighbor in front.neighbors:
                    if neighbor not in mp:
                        mp[neighbor] = Node(neighbor.val)
                        q.append(neighbor)

                    mp[front].neighbors.append(mp[neighbor])

        return mp[node]
