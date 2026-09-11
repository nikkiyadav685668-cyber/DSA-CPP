class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        // sort each row ascending
        for (auto& row : nums) {
            sort(row.begin(), row.end());
        }

        int score = 0;
        // process columns from rightmost (largest) to leftmost
        for (int j = m - 1; j >= 0; j--) {
            int rowMax = 0;
            for (int i = 0; i < n; i++) {
                rowMax = max(rowMax, nums[i][j]);
            }
            score += rowMax;
        }

        return score;
    }
};