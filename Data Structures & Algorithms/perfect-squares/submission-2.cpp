class Solution {
   public:
    int numSquares(int target) {
        vector<int> dp(target + 1, INT_MAX);

        dp[0] = 0;
        //dp[1] = 1;

        for (int num = 1; num <= target; num++) {
            for (int i = 1; i * i <= num; i++) {
                dp[num] = min(dp[num], 1 + dp[num - (i * i)]);
            }
        }
        return dp[target];
    }
};