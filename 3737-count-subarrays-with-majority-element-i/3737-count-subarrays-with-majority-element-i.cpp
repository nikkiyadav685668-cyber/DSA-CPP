class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            
            int count = 0;

            for (int j = i; j < n; j++) {
                
                if (nums[j] == target) {
                    count++;
                }

                int length = j - i + 1;

                // target must appear more than half
                if (count * 2 > length) {
                    ans++;
                }
            }
        }

        return ans;
    }
};