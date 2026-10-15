class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr = 0;

        // Step 1: XOR everything -> xr = a ^ b
        for (int val : nums) {
            xr = xr ^ val;
        }

        // Step 2: rightmost set bit, where a and b differ
        long long diff = xr & -xr;

        // Step 3: split into two groups by that bit and XOR each group
        int a = 0, b = 0;
        for (int val : nums) {
            if (val & diff)
                a = a ^ val;
            else
                b = b ^ val;
        }
        return {a, b};
    }
};