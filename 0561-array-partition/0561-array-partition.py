from typing import List

class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        # Step 1: Sort the array in-place to save memory
        nums.sort()
    
        total_sum = 0
    
        # Step 2: Iterate through the array, skipping one element each time (Nested inside def)
        for i in range(0, len(nums), 2):
            total_sum += nums[i]
        
        # Return statement must also be nested inside def
        return total_sum


  