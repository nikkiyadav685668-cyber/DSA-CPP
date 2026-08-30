class Solution {
public:
    int secondHighest(string s) {
        int largest = -1;
        int second = -1;

        for (int i = 0; i < s.length(); i++) {

            if (isdigit(s[i])) {
                int digit = s[i] - '0';

                if (digit > largest) {
                    second = largest;
                    largest = digit;
                }
                else if (digit > second && digit != largest) {
                    second = digit;
                }
            }
        }

        return second;
    }
};