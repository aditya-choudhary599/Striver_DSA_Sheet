# Question Link : https://www.codingninjas.com/studio/problems/1072980?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

def f(index: int, values: list, weights: list, w: int, dp: list) -> int:
    if index < 0:
        return 0

    if dp[index][w] != -1:
        return dp[index][w]

    not_pick = f(index-1, values, weights, w, dp)
    pick = 0
    if weights[index] <= w:
        pick = values[index]+f(index-1, values, weights, w-weights[index], dp)

    dp[index][w] = max(pick, not_pick)
    return dp[index][w]


def maxProfit(values, weights, n, w):

    dp = [[0]*(w+1) for i in range(0, len(values), 1)]

    for j in range(0, w+1, 1):
        if weights[0] <= j:
            dp[0][j] = values[0]

    for i in range(1, len(values), 1):
        for j in range(0, w+1, 1):
            not_pick = dp[i-1][j]
            pick = 0
            if weights[i] <= j:
                pick = values[i]+dp[i-1][j-weights[i]]
            dp[i][j] = max(pick, not_pick)

    return dp[len(values)-1][w]
