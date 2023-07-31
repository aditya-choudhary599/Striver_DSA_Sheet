# Question Link : https://www.codingninjas.com/studio/problems/1062670?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

def cycleDetection(edges, n, m):
    adj_list = [[] for i in range(0, n+1, 1)]

    for edge in edges:
        adj_list[edge[0]].append(edge[1])
        adj_list[edge[1]].append(edge[0])

    # print(adj_list)

    vis = [False]*(n+1)

    def bfs(pos):
        queue = [[pos, -1]]

        while len(queue) != 0:
            front = queue[0]
            if not vis[front[0]]:
                vis[front[0]] = True

                for connection in adj_list[front[0]]:
                    if vis[connection] == True and connection != front[1]:
                        return True

                    if vis[connection] == False:
                        queue.append([connection, front[0]])

            del queue[0]

        return False

    for i in range(1, n+1, 1):
        if not vis[i]:
            if bfs(i):
                return "Yes"

    return "No"
