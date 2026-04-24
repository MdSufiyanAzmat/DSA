class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0, down = 0, left = 0, right = 0;
        for(char ch : moves){
            if(ch == 'U') up++;
            else if (ch == 'D') down++;
            else if(ch == 'L') left++;
            else right++;
        }
        if(left == right && up == down){
            return true;
        }
        return false;
    }
};