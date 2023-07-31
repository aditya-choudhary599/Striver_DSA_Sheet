# Question Link :  https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution:

    # Function to return a list containing the DFS traversal of the graph.
    def dfsOfGraph(self, n, adj):
        stack = []
        vis = [False] * n
        stack.append(0)
        ans = []

        while len(stack) != 0:
            top = stack[-1]
            stack.pop()

            if not vis[top]:
                vis[top] = True
                ans.append(top)

                for num in adj[top]:
                    stack.append(num)

        return ans
