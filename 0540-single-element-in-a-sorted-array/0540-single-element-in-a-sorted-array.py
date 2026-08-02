class Solution:
    def singleNonDuplicate(self, nums: list[int]) -> int:
        n = len(nums)
        
        # Handle single element base case
        if n == 1:
            return nums[0]
            
        st = 0
        end = n - 1
        
        while st <= end:
            mid = st + (end - st) // 2
            
            # Check boundary conditions safely
            if mid == 0:
                if nums[0] != nums[1]:
                    return nums[mid]
            elif mid == n - 1:
                if nums[n - 1] != nums[n - 2]:
                    return nums[mid]
            # Check if mid itself is the unique element
            elif nums[mid - 1] != nums[mid] and nums[mid] != nums[mid + 1]:
                return nums[mid]
            
            # Binary search logic based on even/odd index pairs
            if mid % 2 == 0:
                # If even index matches the next element, first mismatch is to the right
                if nums[mid] == nums[mid + 1]:
                    st = mid + 1
                else:
                    end = mid - 1
            else:
                # If odd index matches the previous element, first mismatch is to the right
                if nums[mid] == nums[mid - 1]:
                    st = mid + 1
                else:
                    end = mid - 1
                    
        return -1
