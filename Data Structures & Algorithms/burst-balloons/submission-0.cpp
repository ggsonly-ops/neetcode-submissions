class Solution {
   public:
    int helper(int L, int R, vector<int>& paddedNums, vector<vector<int>> &dp) {
        if (L > R) return 0;

        if (dp[L][R] != -1) return dp[L][R];

        int res = 0;
        for (int i = L; i <= R; i++) {
            res = max(res, paddedNums[L - 1] * paddedNums[i] * paddedNums[R + 1] + helper(L, i - 1, paddedNums,dp) +
                               helper(i + 1, R, paddedNums,dp));
        }

        return dp[L][R] = res;
    }
    int maxCoins(vector<int>& nums) {

        int n = nums.size();
        vector<int> paddedNums(n+2,1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        for (int i = 0; i < n; i++) {
            paddedNums[i + 1] = nums[i];
        }

        return helper(1, n, paddedNums,dp);
    }
};
