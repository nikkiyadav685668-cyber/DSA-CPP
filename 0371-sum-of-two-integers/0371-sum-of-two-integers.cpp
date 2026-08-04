class Solution {
public:
    int getSum(int a, int b) {
        unsigned int ua = a;
        unsigned int ub = b;
        
        while (ub != 0) {
            unsigned int carry = ua & ub;
            ua = ua ^ ub;
            ub = carry << 1;
        }
        
        return (int)ua;
    }
};
