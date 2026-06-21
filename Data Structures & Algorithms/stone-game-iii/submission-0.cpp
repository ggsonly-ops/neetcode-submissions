class Solution {
   private:
    int n;
    // memo[cur] stores the maximum relative score the current player can get from index 'cur'
    vector<int> memo;

    int getOptimalMargin(int cur, const vector<int>& stoneValue) {
        if (cur >= n) return 0;
        if (memo[cur] != INT_MIN) return memo[cur];

        int currentTake = 0;
        int maxMargin = INT_MIN;

        // Both Alice and Bob want to maximize: (Stones I take now) - (Best my opponent can do next)
        for (int i = 0; i < 3 && cur + i < n; i++) {
            currentTake += stoneValue[cur + i];
            int opponentBestNext = getOptimalMargin(cur + i + 1, stoneValue);

            maxMargin = max(maxMargin, currentTake - opponentBestNext);
        }

        return memo[cur] = maxMargin;
    }

   public:
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memo.assign(n, INT_MIN);

        // Alice starts first at index 0. ans represents (Alice's Score - Bob's Score)
        int scoreMargin = getOptimalMargin(0, stoneValue);

        if (scoreMargin > 0) return "Alice";
        if (scoreMargin < 0) return "Bob";
        return "Tie";
    }
};
