class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int f = *min_element(nums.begin(), nums.end());
        int s = *max_element(nums.begin(), nums.end());
        unordered_set<int> seen(nums.begin(), nums.end());

        vector<int> ans;
        for (int i = f; i <= s; i++) {
            if (seen.find(i) == seen.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};