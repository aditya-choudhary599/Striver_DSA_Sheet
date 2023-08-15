# Question Link : https://leetcode.com/problems/longest-repeating-character-replacement/description/

# Solution Refrence : https://www.youtube.com/watch?v=gqXU1UyA8pk


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        hashmap = {}

        left = 0
        right = 0

        ans = 0
        while left <= right and right < len(s):
            if s[right] in hashmap:
                hashmap[s[right]] += 1
            else:
                hashmap[s[right]] = 1

            while (right-left+1)-max(hashmap.values()) > k:
                hashmap[s[left]] -= 1
                left += 1

            ans = max(ans, right-left+1)
            right += 1

        return ans
