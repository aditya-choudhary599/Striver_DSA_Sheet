""" Question Link : https://leetcode.com/problems/flipping-an-image/description/ """


class Solution:
    def flipAndInvertImage(self, image: list[list[int]]) -> list[list[int]]:

        for row in image:
            left = 0
            right = len(row)-1

            while left <= right:
                if row[left] == 0 and row[right] == 0:
                    row[left] = 1
                    row[right] = 1
                    left += 1
                    right -= 1

                elif row[left] == 1 and row[right] == 1:
                    row[left] = 0
                    row[right] = 0
                    left += 1
                    right -= 1

                elif row[left] == 1 and row[right] == 0:
                    left += 1
                    right -= 1
                    continue

                elif row[right] == 1 and row[left] == 0:
                    left += 1
                    right -= 1
                    continue

        return image
