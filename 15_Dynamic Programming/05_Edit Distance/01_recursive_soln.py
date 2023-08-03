# Question Link : https://leetcode.com/problems/edit-distance/submissions/1009273274/

class Solution:

    def f(self, i: int, j: int, word_1: str, word_2: str) -> int:
        if j < 0:
            return i+1
        if i < 0:
            return j+1

        if word_1[i] == word_2[j]:
            return self.f(i-1, j-1, word_1, word_2)
        else:
            replace_operation = 1+self.f(i-1, j-1, word_1, word_2)
            delete_operation = 1+self.f(i-1, j, word_1, word_2)
            insert_operation = 1+self.f(i, j-1, word_1, word_2)

            return min(replace_operation, delete_operation, insert_operation)

    def minDistance(self, word_1: str, word_2: str) -> int:
        return self.f(len(word_1)-1, len(word_2)-1, word_1, word_2)
