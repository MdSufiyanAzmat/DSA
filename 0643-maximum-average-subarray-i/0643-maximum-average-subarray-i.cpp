class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
     int n = nums.size();
     int sum = 0;
     for(int i=0; i<k; i++){
        sum += nums[i];
     } 
     int maxSum = sum;
    //  int left = 0;
     for(int i=k; i<n; i++){
        sum = sum - nums[i-k] + nums[i];
        if(sum > maxSum){
            maxSum = sum;
        }
     }
     return double(maxSum)/k;
    }
};