class Solution {
   private:
    void helper(vector<int>& nums, int idx, vector<int> &subset, int target,
                vector<vector<int>>& ans) {

         if(idx >= nums.size() || target < 0) return;
        if (target == 0) {
            ans.push_back(subset);
            return;
        }
       

        subset.push_back(nums[idx]);
        helper(nums, idx, subset, target - nums[idx], ans);
        subset.pop_back();
        helper(nums, idx + 1, subset, target, ans);

    }

   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<int> subset;
        vector<vector<int>> ans;
        helper(nums,0,subset,target,ans);
        return ans;

    }
};
