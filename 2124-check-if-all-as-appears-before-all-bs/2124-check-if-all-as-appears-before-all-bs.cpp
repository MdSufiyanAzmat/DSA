class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        for(int i=0; i<n; i++){
            string str = "";
            for(int j=i; j<n; j++){
                str += s[j];
                if(str == "ba"){
                    return false;
                }
            }
        }
        return true;
    }
};