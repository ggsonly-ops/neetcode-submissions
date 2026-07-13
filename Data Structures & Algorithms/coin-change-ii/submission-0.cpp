class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base case: sum 0 achievable in exactly 1 way (take nothing)
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        // First row: only coins[0] available
        for (int a = coins[0]; a <= amount; a++)
            dp[0][a] = dp[0][a - coins[0]];   // note: dp[0], not dp[-1], since unbounded

        for (int i = 1; i < n; i++) {
            for (int a = 1; a <= amount; a++) {
                int notTaken = dp[i - 1][a];
                int taken = 0;
                if (a >= coins[i])
                    taken = dp[i][a - coins[i]];
                dp[i][a] = notTaken + taken;
            }
        }

        return dp[n - 1][amount];
    }
};