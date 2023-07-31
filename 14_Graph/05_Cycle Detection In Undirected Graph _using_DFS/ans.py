# Question Link : https://www.codingninjas.com/studio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

def cycleDetection(edges, n, m):
    adj_list = [[] for i in range(0, n+1, 1)]

    for edge in edges:
        adj_list[edge[0]].append(edge[1])
        adj_list[edge[1]].append(edge[0])

    # print(adj_list)

    vis = [False]*(n+1)

    def dfs(pos: int, parent: int) -> bool:
        vis[pos] = True

        for i in adj_list[pos]:
            if vis[i] == True and i != parent:
                return True
            elif vis[i] == False:
                if dfs(i, pos):
                    return True

        return False

    for i in range(1, n+1, 1):
        if not vis[i]:
            if dfs(i, -1):
                return "Yes"

    return "No"
