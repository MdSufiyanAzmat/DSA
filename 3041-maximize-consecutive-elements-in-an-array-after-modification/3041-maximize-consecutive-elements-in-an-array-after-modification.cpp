class Solution {
public:
    int n;
    vector<vector<int>> memo;

    int find(vector<int> &nums, int start, int target){
        if (start >= n) return -1;
        int j = lower_bound(nums.begin() + start, nums.end(), target) - nums.begin();
        if(j < n && nums[j] == target){
            return j;
        }
        return -1;
    }

    int solve(int i, int inc, vector<int> &nums){
        if (memo[i][inc] != -1) return memo[i][inc];

        int currValue = nums[i] + inc;
        int len = 1;

        // Next element = currValue + 1  -> keep it as-is (inc = 0)
        int j = find(nums, i + 1, currValue + 1);
        if(j != -1){
            len = max(len, 1 + solve(j, 0, nums));
        }

        // Next element = currValue  -> must increment it (inc = 1)
        j = find(nums, i + 1, currValue);
        if(j != -1){
            len = max(len, 1 + solve(j, 1, nums));
        }

        return memo[i][inc] = len;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        memo.assign(n, vector<int>(2, -1));

        int result = 1;
        for(int i = 0; i < n; i++){
            result = max({result, solve(i, 0, nums), solve(i, 1, nums)});
        }
        return result;
    }
};