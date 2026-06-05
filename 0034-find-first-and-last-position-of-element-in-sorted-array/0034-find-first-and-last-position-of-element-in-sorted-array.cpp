class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
      int n = a.size(), start = 0, end = n - 1;
     int left = -1, right = -1;
     while(start <= end){
        int mid = start + (end - start)/2;
        if(a[mid] == target){
            left = mid;
            end = mid - 1;
        }else if(a[mid] > target){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
     }

     if(left == -1) return {-1, -1};
     start = left;
     end = n - 1;
     while(start <= end){
        int mid = start + (end - start) / 2;
        if(a[mid] == target){
            right = mid;
            start = mid + 1;
        }else if(a[mid] > target){
            end = mid -1;
        }else{
            start = mid + 1;
        }
     }
     return {left, right};
    }
};