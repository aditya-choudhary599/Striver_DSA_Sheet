""" Question Link : https://leetcode.com/problems/reverse-prefix-of-word/description/ """


class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        for i in range(0, len(word), 1):
            if word[i] == ch:
                return word[i::-1]+word[i+1::1]

        return word
