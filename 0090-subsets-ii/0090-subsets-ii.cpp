class Solution {
public:
    void helper(vector<int>& nums, int idx,
                vector<int>& subset,
                vector<vector<int>>& ans) {

        if (idx == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Include current element
        subset.push_back(nums[idx]);
        helper(nums, idx + 1, subset, ans);

        // Backtrack
        subset.pop_back();

        // Skip duplicates
        int i = idx + 1;
        while (i < nums.size() && nums[i] == nums[idx]) {
            i++;
        }

        // Exclude current element and all its duplicates
        helper(nums, i, subset, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subset;

        helper(nums, 0, subset, ans);

        return ans;
    }
};