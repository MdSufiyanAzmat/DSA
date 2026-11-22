class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1;
        int i = 0;
        while (i < s.size()) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                if (num <= prev) return false;
                prev = num;
            } else {
                i++;
            }
        }
        return true;
    }
};