class Solution {

private:
    int helper(vector<int>& nums,int idx,int sum){

        if(idx == nums.size()) {
            return sum;
        }
        return helper(nums,idx+1,sum^nums[idx]) + helper(nums,idx+1,sum);
    }
public:
    int subsetXORSum(vector<int>& nums) {
     
       
        return helper(nums,0,0);
    }
};