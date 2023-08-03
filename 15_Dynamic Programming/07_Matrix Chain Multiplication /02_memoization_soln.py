# Question Link : https://www.codingninjas.com/studio/problems/975344?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

import sys


def f(start, end, mat, dp):
    if start == end:
        return 0

    if (start, end) in dp:
        return dp[(start, end)]

    ans = sys.maxsize
    for x in range(start, end):
        left = f(start, x, mat, dp)
        right = f(x + 1, end, mat, dp)
        ans = min(ans, left + right + mat[start]
                  [0] * mat[x + 1][0] * mat[end][1])

    dp[(start, end)] = ans
    return ans


def matrixMultiplication(arr, n):
    dp = {}
    mat = [(arr[i], arr[i + 1]) for i in range(n - 1)]
    return f(0, n - 2, mat, dp)
