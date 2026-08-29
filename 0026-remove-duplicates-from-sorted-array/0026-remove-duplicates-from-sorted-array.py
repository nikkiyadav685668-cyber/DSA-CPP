from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        left = 0

        for right in range(1, len(nums)):
            if nums[right] != nums[left]:
                left = left + 1
                nums[left] = nums[right]

        return left + 1