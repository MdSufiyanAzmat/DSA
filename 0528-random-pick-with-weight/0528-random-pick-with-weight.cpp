class Solution {
public:
vector<int> prefixSum;
int sum;
    Solution(vector<int>& w) {
        prefixSum.resize(w.size());
        prefixSum[0] = w[0];
        for(int i=1; i<w.size(); i++){
            prefixSum[i] = prefixSum[i-1] + w[i];
        }
        sum = prefixSum.back();
    }
    
    int pickIndex() {
       int target = rand() % sum + 1;
       int left = 0, right = prefixSum.size() - 1;
       while(left < right){
          int mid = left + (right - left) / 2;
          if(prefixSum[mid] == target){
            return mid;
          }else if(prefixSum[mid] < target){
            left = mid+ 1;
          }else{
            right = mid;
          }
       }
return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */