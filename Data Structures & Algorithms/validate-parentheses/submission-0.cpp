class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(int i = 0; i < s.length(); i++) {

            // push the opening brackets into stack
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {

                if(st.empty()) {
                    return false;
                }

                // get the top element of stack and pop it from stack and check if closing bracket has a similar corresponding opening bracket
                char ch = st.top();
                st.pop();

                if((s[i] == ')' && ch != '(') ||
                   (s[i] == ']' && ch != '[') ||
                   (s[i] == '}' && ch != '{')) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};