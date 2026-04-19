class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int min = nums[0];
        int maxSum = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i] + min){
                min = nums[i];
            }else{
                min = nums[i] + min;
            }
            maxSum = max(min, maxSum);
        }
        return maxSum;
    }
};
