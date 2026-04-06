class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int maxLen = 0;
        int n = s.size();
        int left = 0;
        for(int i=0; i<n; i++){
            char c = s[i];
            if(m.find(c) != m.end() && m[c] >= left){
                left = m[c] + 1;
            }
            m[c] = i;
            maxLen = max(maxLen, i-left+1);
        }
        return maxLen;
    }
};