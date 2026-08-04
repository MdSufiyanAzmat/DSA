class Solution {
public:
    bool rotateString(string s, string goal) {
        string str = s + s;
        string ans = "";
        int n = s.size();
        for(int i=0; i<s.size(); i++){
           ans = str.substr(i, n);
           if(ans == goal){
            return true;
           }
        }
        return false;
    }
};