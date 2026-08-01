from typing import List

class Solution:
    def search(self, A: List[int], target: int) -> int:
        st, end = 0, len(A) - 1
        
        while st <= end: 
            mid = st + (end - st) // 2  # Integer division
            
            if A[mid] == target:
                return mid 
            
            # Left half is sorted
            if A[st] <= A[mid]: 
                if A[st] <= target <= A[mid]: 
                    end = mid - 1 
                else:
                    st = mid + 1 
            # Right half is sorted
            else: 
                if A[mid] <= target <= A[end]: 
                    st = mid + 1 
                else:
                    end = mid - 1 
                 
        return -1
