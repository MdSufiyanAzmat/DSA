class Solution {
public:
bool canFinish(vector<int> & piles, int h, int k){
    int hours = 0;
    for(int pile : piles){
        hours += pile / k;
        if(pile % k != 0) hours++;
        if(hours > h) return false;
    }
    return hours <= h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
      int right = *max_element(piles.begin(), piles.end());
      int left = 1;
      int ans;
     while(left <= right){
        int mid = right + (left - right) / 2;
        if(canFinish(piles, h, mid)){
            ans = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
     }
     return ans;
    }
};