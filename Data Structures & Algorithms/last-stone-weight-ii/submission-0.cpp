class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += stones[i];
        }

        int target = sum / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (stones[i - 1] <= j) take = dp[i - 1][j - stones[i - 1]];
                dp[i][j] = take | notTake;
            }
        }

        int maxi = 0;
        for (int j = 0; j <= target; j++) {
            if (dp[n][j]) {
                maxi = j; 
            }
        }

        // Return the absolute remaining stone weight difference
        return sum - 2 * maxi;
    }
};