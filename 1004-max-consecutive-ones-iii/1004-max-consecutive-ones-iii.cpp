class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount = 0;
        int left = 0;
        int maxCount = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zeroCount++;
            }
            while(zeroCount > k){
                if(nums[left] == 0){
                    zeroCount--;
                }
                left++;
            }
            maxCount = max(maxCount, i-left+1);
        }
        return maxCount;
    }
};