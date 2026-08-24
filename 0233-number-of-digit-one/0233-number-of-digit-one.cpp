class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        
        long long count = 0;
        
        // Loop through each digit place: 1, 10, 100, 1000...
        // Using long long prevents integer overflow when i * 10 exceeds INT_MAX
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            long long left = n / divider;
            long long curr = (n / i) % 10;
            long long right = n % i;
            
            if (curr == 0) {
                count += left * i;
            } 
            else if (curr == 1) {
                count += left * i + right + 1;
            } 
            else {
                count += (left + 1) * i;
            }
        }
        
        return count;
    }
};