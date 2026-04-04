class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int m = s.length();
        int n = p.length();
        
        if (m < n) return result;
        
        // Frequency arrays for characters (a-z)
        vector<int> sCount(26, 0);
        vector<int> pCount(26, 0);

        for(char c : p){
            pCount[c - 'a']++;
        }

        for(int i=0; i<n; i++){
            sCount[s[i] - 'a']++;
        }
        if(sCount == pCount){
            result.push_back(0);
        }

        for(int i=n; i<m; i++){
            sCount[s[i] - 'a']++;
            sCount[s[i-n] - 'a']--;
            if(sCount == pCount){
                result.push_back(i-n+1);
            }
        }
        return result;
    }
};