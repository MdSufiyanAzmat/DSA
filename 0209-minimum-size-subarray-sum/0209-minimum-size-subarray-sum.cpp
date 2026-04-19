class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0, i=0;
        int val = 0;
        int ans = INT_MAX;
        while(j<nums.size()){
            val += nums[j];
            while(val >= target){
                ans = min(ans, j-i+1);
                val -= nums[i];
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};