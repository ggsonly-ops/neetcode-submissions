
class Solution {
  public:
    /* Function to calculate the minimum number 
    of operations required to transform S1 into S2*/

    //dp[i][j] = minimum number of operations (insert, delete, replace) to convert start[0..i-1] to target[0..j-1]
    
    int minDistance(string start, string target) {
        int n = start.size();
        int m = target.size();

        // Create a DP table to store edit distances
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Initialize the first row and column
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        // Fill in the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match, no additional cost
                if (start[i - 1] == target[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                // Take minimum of three choices
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }

        // The value at dp[n][m] contains the edit distance
        return dp[n][m];
    }
};