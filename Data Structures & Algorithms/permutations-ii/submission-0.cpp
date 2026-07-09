class Solution {
private:
    void recurPermute(int idx, vector<int>& nums, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used; // values already tried for THIS position, this loop
        for (int i = idx; i < nums.size(); i++) {
            if (used.count(nums[i])) continue; // skip if this value was already tried here
            used.insert(nums[i]);

            swap(nums[idx], nums[i]);
            recurPermute(idx + 1, nums, ans);
            swap(nums[idx], nums[i]); // undo
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};