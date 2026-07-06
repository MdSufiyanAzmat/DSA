class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& i) {
        sort(i.begin(), i.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] == b[0])
               return a[1] > b[1];
            return a[0] < b[0];
        });

        int count = 0;
        int maxEnd = 0;

        for(auto &in : i){
            if(in[1] > maxEnd){
                count++;
                maxEnd = in[1];
            }
        }
        return count;
    }
};