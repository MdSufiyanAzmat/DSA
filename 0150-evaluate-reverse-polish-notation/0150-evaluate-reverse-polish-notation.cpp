class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;  // ✅ Fixed: stack of ints, not chars
        
        for(int i = 0; i < tokens.size(); i++){
            // Check if token is a number (handles negative numbers)
            if(isdigit(tokens[i][0]) || (tokens[i].size() > 1 && tokens[i][0] == '-')) {
                st.push(stoi(tokens[i]));  // ✅ Fixed: removed extra parenthesis
            }
            else if(tokens[i] == "+"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a + b);
            }
            else if(tokens[i] == "-"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a - b);
            }
            else if(tokens[i] == "*"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a * b);
            }
            else if(tokens[i] == "/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(a / b);
            }
        }
        return st.top();
    }
};