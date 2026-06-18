class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for (int i = 0; i < n; i++) totSum += nums[i];

        if (totSum % 2 != 0) return false;
        int target = totSum / 2;

        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i < n+1; i++) {
            for(int j=0;j<=target;j++){
                bool notTake=dp[i-1][j];
                bool take=false;
                if(nums[i-1]<=j) take=dp[i-1][j-nums[i-1]];
                dp[i][j]=notTake|take;
            }
        }
        return dp[n][target];
    }
};
