class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int m = s.length();
        int n = p.length();
        
        if (m < n) return result;
        
        // Frequency arrays for characters (a-z)
        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        
        // Count frequencies in p
        for (char c : p) {
            pCount[c - 'a']++;
        }
        
        // Initial window of size n
        for (int i = 0; i < n; i++) {
            sCount[s[i] - 'a']++;
        }
        
        // Check first window
        if (pCount == sCount) {
            result.push_back(0);
        }
        
        // Slide the window
        for (int i = n; i < m; i++) {
            // Add new character
            sCount[s[i] - 'a']++;
            // Remove old character
            sCount[s[i - n] - 'a']--;
            
            // Check if current window is an anagram
            if (pCount == sCount) {
                result.push_back(i - n + 1);
            }
        }
        
        return result;
    }
};