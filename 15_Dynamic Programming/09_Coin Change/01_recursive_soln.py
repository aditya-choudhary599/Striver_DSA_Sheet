# Question Link : https://leetcode.com/problems/coin-change/description/

from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        coins.sort()

        def helper(index: int, amount_1: int) -> int:
            if amount_1 == 0:
                return 0
            if index == 0:
                if amount_1 % coins[0] == 0:
                    return amount_1//coins[0]
                else:
                    return -1

            not_pick = helper(index-1, amount_1)
            pick = -1
            if coins[index] <= amount_1:
                rcall = helper(index, amount_1-coins[index])
                if rcall != -1:
                    pick = 1+rcall

            if not_pick != -1 and pick != -1:
                return min(not_pick, pick)
            elif not_pick == -1:
                return pick
            elif pick == -1:
                return not_pick
            else:
                return -1

        return helper(n-1, amount)
