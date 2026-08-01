from typing import List

class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        st = 1
        end = len(arr) - 2

        while st <= end:
            mid = st + (end - st) // 2  # Fixed to floor division
            
            if arr[mid-1] < arr[mid] and arr[mid] > arr[mid+1]:
                return mid
            elif arr[mid - 1] < arr[mid]:  # Fixed to 'elif'
                st = mid + 1
            else:  
                end = mid - 1
                
        return -1  # Fixed indentation to return only if loop finishes
