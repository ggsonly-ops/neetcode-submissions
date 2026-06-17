class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int amt = 1; amt <= amount; amt++) {
            for (int coin = 0; coin < coins.size(); coin++) {
                if (coins[coin] <= amt && dp[amt - coins[coin]]!=INT_MAX) {
                    int take = dp[amt - coins[coin]] + 1;
                    dp[amt] = min(dp[amt], take);
                }
            }
        }

        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
};
