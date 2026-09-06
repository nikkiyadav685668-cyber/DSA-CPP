class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;

        int mini = nums[0];
        int maxi = nums[0];

        for (int x : nums) {
            mini = min(mini, x);
            maxi = max(maxi, x);
        }

        for (int i = mini; i <= maxi; i++) {
            
            int flag = 0;

            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};