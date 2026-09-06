class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int, int> mp;

        // for (int i = 0; i < nums.size(); i++) {
        //     int complement = target - nums[i];

        //     if (mp.find(complement) != mp.end()) {
        //         return {mp[complement], i};
        //     }

        //     mp[nums[i]] = i;
        // }

        // return {};
        map<int,int> mpp;
        int n = nums.size();
        for(int i =0; i<n;i++){
            int num = nums[i];
            int complement = target - num;
            if(mpp.find(complement) != mpp.end()){
                return {mpp[complement],i};
            }
            mpp[num] = i;
        }
        return {-1,-1};
    }
};