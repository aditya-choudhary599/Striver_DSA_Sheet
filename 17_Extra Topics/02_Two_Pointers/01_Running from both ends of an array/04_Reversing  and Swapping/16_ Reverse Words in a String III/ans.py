# Question Link : https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

class Solution:
    def reverseWords(self, s: str) -> str:
        temp=s.split(' ')
        temp=[item[::-1] for item in temp]
        return ' '.join(temp)