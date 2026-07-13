class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int x : nums) totalSum += x;

        // Impossible cases
        if (abs(target) > totalSum) return 0;
        if ((target + totalSum) % 2 != 0) return 0;

        int P = (target + totalSum) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(P + 1, 0));

        // base case: empty subset always sums to 0
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        // first element on its own
        if (nums[0] <= P)
            dp[0][nums[0]] += 1;

        for (int i = 1; i < n; i++) {
            for (int s = 0; s <= P; s++) {
                int notTaken = dp[i - 1][s];
                int taken = (s >= nums[i]) ? dp[i - 1][s - nums[i]] : 0;
                dp[i][s] = notTaken + taken;
            }
        }

        return dp[n - 1][P];
    }
};