class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        vector<int> ans;
        unordered_set<int> s;

        int n = grid.size();

        int a = 0; // repeated number
        int b = 0; // missing number

        int expSum = 0;
        int actualSum = 0;

        // Find repeated number and actual sum
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                actualSum += grid[i][j];

                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                }

                s.insert(grid[i][j]);
            }
        }

        // Expected sum from 1 to n*n
        int total = n * n;
        expSum = total * (total + 1) / 2;

        // Find missing number
        b = expSum + a - actualSum;

        ans.push_back(a);
        ans.push_back(b);

        return ans;
    }
};