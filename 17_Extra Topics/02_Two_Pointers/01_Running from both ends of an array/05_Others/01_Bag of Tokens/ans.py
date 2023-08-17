# Question Link : https://leetcode.com/problems/bag-of-tokens/description/

# Solution Ref Link : https://www.youtube.com/watch?v=vMbSUtKi7vk&t=170s

class Solution:
    def bagOfTokensScore(self, tokens: list[int], power: int) -> int:
        tokens.sort()

        left = 0
        right = len(tokens)-1
        curr_score = 0
        max_score = 0

        while left <= right:
            if power < tokens[left] and curr_score > 0:
                curr_score -= 1
                # Instead of taking tokens[left] we take tokens[right] face down so that we can get max power
                power += tokens[right]
                right -= 1

            elif power >= tokens[left]:
                curr_score += 1
                # We take tokens[left] as this will increase our score and reduce our power reduction will also be minimum
                max_score = max(curr_score, max_score)
                power -= tokens[left]
                left += 1

            else:
                return max_score

        return max_score
