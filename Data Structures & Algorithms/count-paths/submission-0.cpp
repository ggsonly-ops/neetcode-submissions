class Solution {
   private:
    int func(int m, int n, vector<vector<int>>& dp) {
        vector<int> prev(n, 1);  // first row is all 1s

        for (int i = 1; i < m; i++) {
            vector<int> curr(n, 1);  // first col is always 1
            for (int j = 1; j < n; j++) {
                curr[j] = prev[j] + curr[j - 1];
            }
            prev = curr;
        }
        return prev[n - 1];
    }

   public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m, n, dp);
        // TC: O(m*n), SC: O(m*n)
    }
};
