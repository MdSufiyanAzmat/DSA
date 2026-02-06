class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> twice(2*n);
        if(n == 0){
            return;
        }
        k = k % n;
        for(int i=0; i<2*n; i++){
            twice[i] = nums[i % n];
        }
        for(int i=0; i<n; i++){
            nums[i] = twice[n - k - i];
        }
    }
};