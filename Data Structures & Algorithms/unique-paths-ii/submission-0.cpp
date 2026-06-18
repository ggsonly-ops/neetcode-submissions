class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        if (matrix[0][0] == 1)
            return 0;
        else
            dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1)
                    dp[i][j] = 0;
                else {
                    if (i >= 1) dp[i][j] += dp[i - 1][j];
                    if (j >= 1) dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};