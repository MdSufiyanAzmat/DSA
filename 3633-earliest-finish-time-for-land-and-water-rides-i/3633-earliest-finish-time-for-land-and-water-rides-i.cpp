class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;
        
        // Try every combination of one land ride and one water ride
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Option 1: Land first, then water
                int landFinish = landStartTime[i] + landDuration[i];
                int waterStart = max(waterStartTime[j], landFinish);
                int finish1 = waterStart + waterDuration[j];
                
                // Option 2: Water first, then land
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landStart = max(landStartTime[i], waterFinish);
                int finish2 = landStart + landDuration[i];
                
                // Take the better order for this pair
                int pairFinish = min(finish1, finish2);
                ans = min(ans, pairFinish);
            }
        }
        
        return ans;
    }
};