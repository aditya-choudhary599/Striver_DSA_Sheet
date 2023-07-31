# Question Link :  https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution:

    # Function to return a list containing the DFS traversal of the graph.
    def dfsOfGraph(self, n, adj):
        ans = []
        vis = [False]*n

        def f(pos, vis):
            ans.append(pos)
            vis[pos] = True

            for i in adj[pos]:
                if not vis[i]:
                    f(i, vis)

            return

        f(0, vis)

        return ans
