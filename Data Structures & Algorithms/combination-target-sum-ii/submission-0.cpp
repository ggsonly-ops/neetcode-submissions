class Solution {
   private:
    void helper(vector<int>& nums, int idx, vector<int>& subset, int target,
                vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(subset);
            return;
        }
        if (idx >= nums.size() || target < 0) return;

        subset.push_back(nums[idx]);
        helper(nums, idx + 1, subset, target - nums[idx], ans);
        subset.pop_back();
        int next = idx + 1;
        while (next < nums.size() && nums[next] == nums[idx]) {
            next++;
        }
        helper(nums, next, subset, target, ans);
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> ans;
        helper(nums, 0, subset, target, ans);
        return ans;
    }
};
