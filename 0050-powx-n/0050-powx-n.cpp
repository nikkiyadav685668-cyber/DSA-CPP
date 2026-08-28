class Solution {
public:
    double myPow(double x, int n) {

        if(n == 0) return 1.0;
        if(x == 0) return 0.0;
        if(x == 1) return 1.0;

        long long binForm = n;

        if(binForm < 0) {
            x = 1 / x;
            binForm = -binForm;
        }

        double ans = 1;

        while(binForm > 0) {

            // If current binary bit is 1
            if(binForm % 2 == 1) {
                ans *= x;
            }

            // Square x
            x *= x;

            // Move to next binary bit
            binForm /= 2;
        }

        return ans;
    }
};