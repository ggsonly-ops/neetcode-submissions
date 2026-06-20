class Solution {
   public:
    // dp[i][j] = length of the longest increasing path starting at (i,j)

    int helper(int i, int j, int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];

        int maxPath = 1;
        if (i + 1 < n && matrix[i + 1][j] > matrix[i][j]) {
            maxPath = max(maxPath, 1 + helper(i + 1, j, n, m, matrix, dp));
        }
        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
            maxPath = max(maxPath, 1 + helper(i - 1, j, n, m, matrix, dp));
        }
        if (j + 1 < m && matrix[i][j + 1] > matrix[i][j]) {
            maxPath = max(maxPath, 1 + helper(i, j + 1, n, m, matrix, dp));
        }
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
            maxPath = max(maxPath, 1 + helper(i, j - 1, n, m, matrix, dp));
        }

        return dp[i][j] = maxPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxi = max(maxi, helper(i, j, n, m, matrix, dp));
            }
        }
        return maxi;
    }
};
