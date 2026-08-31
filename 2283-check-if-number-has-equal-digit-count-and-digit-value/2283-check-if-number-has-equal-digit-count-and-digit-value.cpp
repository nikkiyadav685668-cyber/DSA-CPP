class Solution {
public:
    bool digitCount(string num) {
        int freq[10] = {0};

        // Count frequency of every digit
        for (char ch : num) {
            freq[ch - '0']++;
        }

        // Check the condition
        for (int i = 0; i < num.length(); i++) {
            int required = num[i] - '0';

            if (freq[i] != required) {
                return false;
            }
        }

        return true;
    }
};