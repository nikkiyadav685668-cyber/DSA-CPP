class Solution {
public:
    void nextPermutation(vector<int>& A) {
        
        int pivot = -1;
        int n = A.size();

        // 1. Find pivot
        for(int i = n - 2; i >= 0; i--) {
            if(A[i] < A[i + 1]) {
                pivot = i;
                break;
            }
        }

        // No pivot -> array is in descending order
        if(pivot == -1) {
            reverse(A.begin(), A.end());
            return;
        }
        for(int i = n - 1; i > pivot; i--) {
            if(A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;   // ⭐ Important
            }
        }

        // 3. Reverse the part after pivot
        int i = pivot + 1;
        int j = n - 1;

        while(i <= j) {
            swap(A[i++], A[j--]);
        }
    }
};