class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> dp(ROWS + 1, vector<int>(COLS + 1, INT_MAX));
        dp[ROWS - 1][COLS] = 0;

        for (int r = ROWS - 1; r >= 0; r--) {
            for (int c = COLS - 1; c >= 0; c--) {
                dp[r][c] = grid[r][c] + min(dp[r + 1][c], dp[r][c + 1]);
            }
        }

        return dp[0][0];
    }
};