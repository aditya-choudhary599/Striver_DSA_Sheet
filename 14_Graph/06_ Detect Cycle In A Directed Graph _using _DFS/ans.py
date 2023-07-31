# QUestion Link : https://www.codingninjas.com/studio/problems/1062626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

def detectCycleInDirectedGraph(n, edges):
    adj_list = [[] for i in range(n + 1)]

    for edge in edges:
        adj_list[edge[0]].append(edge[1])

    vis = [False] * (n + 1)

    def dfs(pos):
        if vis[pos]:
            return True

        vis[pos] = True
        for con in adj_list[pos]:
            if dfs(con):
                return True

        vis[pos] = False
        return False

    for i in range(1, n + 1):
        if not vis[i] and dfs(i):
            return True

    return False
