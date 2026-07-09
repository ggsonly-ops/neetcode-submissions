class Solution {
private:
    void helper(vector<int>& nums, int idx, vector<int>& subset, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Include nums[idx]
        subset.push_back(nums[idx]);
        helper(nums, idx + 1, subset, ans);
        subset.pop_back();

        // Exclude nums[idx] -- but skip past any duplicates of it first
        int next = idx + 1;
        while (next < nums.size() && nums[next] == nums[idx]) {
            next++;
        }
        helper(nums, next, subset, ans);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        helper(nums, 0, subset, ans);
        return ans;
    }
};