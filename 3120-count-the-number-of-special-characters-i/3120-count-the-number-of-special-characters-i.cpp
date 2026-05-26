class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowerFreq(26, 0);
        vector<int> upperFreq(26, 0);
        for(char c : word){
            if(islower(c)){
                lowerFreq[c - 'a']++;
            }else{
                upperFreq[c - 'A']++;
            }
        }
        int specialCharacters = 0;
        for(int i=0; i<26; i++){
            if(lowerFreq[i] >= 1 && upperFreq[i] >= 1){
                specialCharacters++;
            }
        }
        return specialCharacters;
    }
};