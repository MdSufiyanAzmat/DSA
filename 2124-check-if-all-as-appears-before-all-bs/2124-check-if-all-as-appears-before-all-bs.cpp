class Solution {
public:
    bool checkString(string s) {
        string ans = s;
        sort(s.begin(), s.end());
        return s == ans;
    }
};