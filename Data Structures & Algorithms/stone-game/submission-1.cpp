class Solution {
public:
    int helper(int i, int j, vector<int>& piles, vector<vector<int>>& memo) {
        // Your base case checking if all remaining piles are gone
        int remaining_piles = j - i + 1;
        if (remaining_piles == 0) return 0;

        // Check if we already calculated this specific board state
        if (memo[i][j] != -1e9) return memo[i][j];

        if (remaining_piles % 2 == 0) {
            // ALICE'S TURN: Maximize her score difference
            int pickLeft  = piles[i] + helper(i + 1, j, piles, memo);
            int pickRight = piles[j] + helper(i, j - 1, piles, memo);
            return memo[i][j] = max(pickLeft, pickRight);
        } 
        else {
            // BOB'S TURN: Minimize Alice's advantage (by subtracting his pick)
            int pickLeft  = -piles[i] + helper(i + 1, j, piles, memo);
            int pickRight = -piles[j] + helper(i, j - 1, piles, memo);
            return memo[i][j] = min(pickLeft, pickRight); 
        }
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // Initializing with -1e9 since game scores can naturally be negative
        vector<vector<int>> memo(n, vector<int>(n, -1e9));
        
        // Final verification: If Alice - Bob > 0, Alice wins!
        return helper(0, n - 1, piles, memo) > 0;
    }
};
