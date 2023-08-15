# Question Link : https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

from typing import List
import sys


class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        ans=sys.maxsize
        hashmap={}

        for i in range(0,len(cards),1):
            if cards[i] in hashmap:
                ans=min(ans,i-hashmap[cards[i]]+1)

                # To mark the nearest location for further reference
                hashmap[cards[i]]=i
            
            else:
                hashmap[cards[i]]=i
        
        if ans==sys.maxsize:
            return -1
        else:
            return ans