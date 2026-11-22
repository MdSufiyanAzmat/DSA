class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0, dp = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == 'b'){
                bCount++;
            }else if(bCount > 0 and s[i] == 'a') {
                dp = min(dp+1, bCount);
            }
        }
        return dp;
    }
};