class Solution {
public:
    int searchInsert(vector<int>& a, int target) {
    int st = 0, end = a.size() - 1;
    int mid;
    while(st <= end){
        mid = st + (end - st) / 2;
        if(a[mid] == target){
            return mid;
        }else if (a[mid] > target){
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    return st;
     }     
};