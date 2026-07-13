class Solution {
public:
    // memo[i][M] stores the maximum relative score margin the current player can get from index 'i' with 'M'
    int helper(int i, int M, vector<int>& piles, vector<vector<int>>& memo) {
        if (i >= piles.size()) return 0;
        if (memo[i][M] != -1) return memo[i][M];

        int currentTake = 0;
        int maxMargin = INT_MIN;

        // Both players play perfectly to maximize: (What I take now) - (What opponent can get next)
        for (int X = 1; X <= 2 * M && i + X - 1 < piles.size(); X++) {
            currentTake += piles[i + X - 1];
            int opponentBestNext = helper(i + X, max(M, X), piles, memo);
            
            maxMargin = max(maxMargin, currentTake - opponentBestNext);
        }

        return memo[i][M] = maxMargin;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // 1. Calculate total stones in the game
        int totalStones = accumulate(piles.begin(), piles.end(), 0);
        
        // 2. Maximum possible value for M is n
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        
        // 3. Alice's maximum margin over Bob starting at index 0 with M = 1
        int scoreMargin = helper(0, 1, piles, memo);
        
        // 4. Convert the margin back to Alice's absolute score
        // Alice + Bob = totalStones
        // Alice - Bob = scoreMargin
        // 2 * Alice = totalStones + scoreMargin
        return (totalStones + scoreMargin) / 2;
    }
};

