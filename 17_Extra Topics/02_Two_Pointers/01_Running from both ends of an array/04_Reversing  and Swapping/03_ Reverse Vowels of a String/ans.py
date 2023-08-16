""" Question Link : https://leetcode.com/problems/reverse-vowels-of-a-string/description/ """


class Solution:

    def is_vowel(self, temp: chr) -> bool:
        temp = temp.lower()
        return temp == 'a' or temp == 'e' or temp == 'i' or temp == 'o' or temp == 'u'

    def reverseVowels(self, s: str) -> str:
        s_list = list(s)
        left = 0

        while left < len(s_list) and not self.is_vowel(s_list[left]):
            left += 1

        if left == len(s_list):
            # As there are no vowels in the string
            return s

        right = len(s_list) - 1

        while right >= 0 and not self.is_vowel(s_list[right]):
            right -= 1

        while left <= right:
            s_list[left], s_list[right] = s_list[right], s_list[left]

            left += 1
            right -= 1

            while left < len(s_list) and not self.is_vowel(s_list[left]):
                left += 1

            while right >= 0 and not self.is_vowel(s_list[right]):
                right -= 1

        return ''.join(s_list)
