class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int currSum=nums[0];
        int maxSum=nums[0];
        int currMin = nums[0];
        int minSum = nums[0];
        int totalSum=nums[0];

        for(int i=1 ; i < nums.size() ; i++){
            currSum=max(currSum + nums[i],nums[i]);
            maxSum=max(currSum,maxSum);
            currMin=min(currMin + nums[i], nums[i]);
            minSum=min(currMin,minSum);
            totalSum+=nums[i];
        }
        if(maxSum < 0) return maxSum;
        return max(maxSum,totalSum - minSum);
    }
};