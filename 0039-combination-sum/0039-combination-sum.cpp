class Solution {
public:

    void getAllCombination(vector<int>& arr, int idx, int tar,
                            vector<vector<int>>& ans,
                            vector<int>& combin) {

        // Target achieved
        if (tar == 0) {
            ans.push_back(combin);
            return;
        }

        // Invalid condition
        if (idx == arr.size() || tar < 0) {
            return;
        }

        // Include arr[idx]
        combin.push_back(arr[idx]);

        // Stay at same index because we can reuse the number
        getAllCombination(arr, idx, tar - arr[idx], ans, combin);

        combin.pop_back();

        // Exclude arr[idx] and move to next element
        getAllCombination(arr, idx + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {

        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombination(arr, 0, target, ans, combin);

        return ans;
    }
};