class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string ans = s;

        int n = s.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(s[i], s[j]);

                if (s > ans)
                    ans = s;

                swap(s[i], s[j]); // backtrack
            }
        }

        return stoi(ans);
    }
};