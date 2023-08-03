# Question Link : https://www.codingninjas.com/studio/problems/1072980?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

def f(index: int, values: list, weights: list, w: int) -> int:
    if index < 0:
        return 0

    not_pick = f(index-1, values, weights, w)
    pick = 0
    if weights[index] <= w:
        pick = values[index]+f(index-1, values, weights, w-weights[index])

    return max(pick, not_pick)


def maxProfit(values, weights, n, w):

    return f(n-1, values, weights, w)
