# Question Link : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

from typing import List


class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        marked = [False] * (n + 1)
        marked[0] = True
        marked[n] = True
        mp = {cut: True for cut in cuts}

        def get_boundaries(x, marked, n):
            ans = [None, None]

            # Getting the nearest left boundary
            for i in range(x - 1, -1, -1):
                if marked[i]:
                    ans[0] = i
                    break

            # Getting the nearest right boundary
            for i in range(x + 1, n + 1, 1):
                if marked[i]:
                    ans[1] = i
                    break

            return ans

        def f(mp, marked, n):
            ans = float('inf')
            for key in mp:
                if mp[key]:
                    # Recursive call
                    left, right = get_boundaries(key, marked, n)
                    curr_cost = right - left
                    mp[key] = False
                    marked[key] = True
                    ans = min(ans, curr_cost + f(mp, marked, n))

                    # Backtracking step
                    mp[key] = True
                    marked[key] = False

            return 0 if ans == float('inf') else ans

        return f(mp, marked, n)
