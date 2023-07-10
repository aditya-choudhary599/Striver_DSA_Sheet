# Question Link : https://leetcode.com/problems/4sum/description/

# here the base logic is same as that of the Three Sum Problem

class Solution:
    def twoSum(self, nums, start, n, target):
        if start >= n:
            return []
        low = start
        high = n - 1
        ans = []
        while low < high:
            if nums[low] + nums[high] == target:
                ans.append([nums[low], nums[high]])

                low += 1
                while low < high and nums[low] == nums[low - 1]:
                    low += 1

                high -= 1
                while low < high and nums[high] == nums[high + 1]:
                    high -= 1
            elif nums[low] + nums[high] < target:
                low += 1
            else:
                high -= 1
        return ans

    def threeSum(self, nums, start, n, target):
        ans = []
        i = start
        while i < n:
            small_ans = self.twoSum(nums, i + 1, n, target - nums[i])
            size = len(small_ans)
            for j in range(size):
                ans.append([nums[i], small_ans[j][0], small_ans[j][1]])
            i += 1
            while i < n and nums[i] == nums[i - 1]:
                i += 1
        return ans

    def fourSum(self, nums, target):
        n = len(nums)
        nums.sort()
        ans = []
        i = 0
        while i < n:
            small_ans = self.threeSum(nums, i + 1, n, target - nums[i])
            size = len(small_ans)
            for j in range(size):
                ans.append([nums[i], small_ans[j][0],
                           small_ans[j][1], small_ans[j][2]])
            i += 1
            while i < n and nums[i] == nums[i - 1]:
                i += 1
        return ans
