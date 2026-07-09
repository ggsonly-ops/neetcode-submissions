class Solution {

private:
    void helper(vector<int>& nums,int idx,int sum,int &ans){

        if(idx == nums.size()) {
            ans+=sum;
            return;
        }
        helper(nums,idx+1,sum^nums[idx],ans);
        helper(nums,idx+1,sum,ans);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        helper(nums,0,0,ans);
        return ans;
    }
};