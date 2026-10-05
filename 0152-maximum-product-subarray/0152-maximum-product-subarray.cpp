class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int pro = 1;
        int suff = 1;
        for(int i =0; i<n; i++){
            if(pro == 0) pro = 1;
            if(suff == 0) suff =1;

            pro = pro * nums[i];
            suff = suff * nums[n-i-1];
           ans = max(ans,max(pro,suff));
        }
        return ans;
    }
};