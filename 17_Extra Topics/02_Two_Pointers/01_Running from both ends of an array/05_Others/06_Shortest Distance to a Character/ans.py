""" Question Link : https://leetcode.com/problems/shortest-distance-to-a-character/description/ """

class Solution:
    def shortestToChar(self, s: str, c: str) -> list[int]:
        right=[0]*len(s)
        last_occr_of_char=1e9
        
        for i in range(len(s)-1,-1,-1):
            if s[i]==c:
                right[i]=0
                last_occr_of_char=i
            else:
                right[i]=last_occr_of_char-i
        
        # print(right)

        left=[0]*len(s)
        last_occr_of_char=int(-1e9)

        for i in range(0,len(s),1):
            if s[i]==c:
                left[i]=0
                last_occr_of_char=i
            else:
                left[i]=i-last_occr_of_char

        # print(left)
        
        ans=[min(left[i],right[i]) for i in range(0,len(s),1)]

        return ans