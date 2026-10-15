class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> seen;
        int ans = 0;

        for (int val : nums) {
            if (seen.count(val)) {
                ans = ans ^ val;    // seen before, so it is the second time
            } else {
                seen.insert(val);
            }
        }
        return ans;
    }
};