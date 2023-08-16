# Question Link : https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution:
    def reverseWords(self, s: str) -> str:
        temp = s.split(' ')
        print(temp)
        temp = [item for item in temp if item != ""]
        print(temp)
        temp.reverse()
        return ' '.join(temp)
