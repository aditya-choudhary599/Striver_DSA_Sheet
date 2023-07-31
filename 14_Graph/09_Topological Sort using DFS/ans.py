# Question Link : https://www.codingninjas.com/studio/problems/982938?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

def topologicalSort(edges, v, e):
    graph = [[[], []] for i in range(v)]
    # here first is for in and second is for out

    for q in edges:
        if q[0] is not None and q[1] is not None:  # Validate the input to avoid NoneType
            graph[q[0]][1].append(q[1])
            graph[q[1]][0].append(q[0])

    ans = []
    sats = [False] * v

    def dfs(idx):
        if sats[idx]:
            return

        for pre in graph[idx][0]:
            if not sats[pre]:
                return

        sats[idx] = True
        ans.append(idx)

        for out in graph[idx][1]:
            dfs(out)

    for i in range(v):
        if not sats[i]:
            dfs(i)

    return ans
