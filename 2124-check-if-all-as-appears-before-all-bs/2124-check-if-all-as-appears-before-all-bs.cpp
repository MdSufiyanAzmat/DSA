class Solution {
public:
    bool checkString(string s) {
        int left = INT_MIN;
        int right = INT_MAX;
        bool checked = false;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a'){
                left = i;
            }else if(!checked){
                right = i;
                checked = true;
            }
        }
        return right >= left;
    }
};