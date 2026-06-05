class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> numStack;
        string currentStr = "";
        int num = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                // Build the complete number (handles multi-digit numbers)
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i] == '[') {
                // Push current state to stacks
                numStack.push(num);
                strStack.push(currentStr);
                // Reset for the new context
                num = 0;
                currentStr = "";
            }
            else if(s[i] == ']') {
                // Decode the current string
                string temp = currentStr;
                currentStr = strStack.top();
                strStack.pop();
                
                int repeatCount = numStack.top();
                numStack.pop();
                
                // Repeat the string
                for(int j = 0; j < repeatCount; j++) {
                    currentStr += temp;
                }
            }
            else {
                // Regular character
                currentStr += s[i];
            }
        }
        
        return currentStr;
    }
};