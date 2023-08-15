# Question Link : https://leetcode.com/problems/fruit-into-baskets/description/

class Solution:

    def satisfy(self, temp: list[int]) -> bool:
        my_set = set(temp)
        return len(my_set) <= 2

    def totalFruit(self, fruits: list[int]) -> int:
        left = 0
        ans = 0
        basket = {}  # Using a dictionary to store fruit counts

        for right in range(len(fruits)):
            fruit = fruits[right]
            if fruit in basket:
                basket[fruit] += 1
            else:
                basket[fruit] = 1
            
            while len(basket) > 2:  # If more than 2 fruit types, move left pointer
                left_fruit = fruits[left]
                basket[left_fruit] -= 1
                if basket[left_fruit] == 0:
                    del basket[left_fruit]
                left += 1

            ans = max(ans, right - left + 1)

        return ans
