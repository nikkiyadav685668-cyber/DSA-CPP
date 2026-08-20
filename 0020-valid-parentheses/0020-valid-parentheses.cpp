class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for (int i = 0; i < str.size(); i++) {

            // Opening brackets
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                st.push(str[i]);
            }
            else {
                // No opening bracket available
                if (st.empty()) {
                    return false;
                }

                // Check matching brackets
                if ((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '{' && str[i] == '}') ||
                    (st.top() == '[' && str[i] == ']')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // Stack must be empty
        return st.empty();
    }
};