class Solution {
public:
    bool completePrime(int num) {
        // Corner cases: numbers less than or equal to 1 are not prime
        if (num <= 1) {
            return false;
        }
        
        // Check for factors from 2 up to the square root of num
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false; // Found a factor, so it's not prime
            }
        }
        
        return true; // No factors found, it is prime
    }
};