
class Solution {
   public:
    // alice==1 means alice
    // alice==0 means bob

    int helper(int i, int alice, vector<int>& piles, int M, vector<vector<vector<int>>>& memo) {
        if (i == piles.size()) return 0;

        // 1. Check if the subproblem is already cached
        if (memo[alice][i][M] != -1) return memo[alice][i][M];

        int total = 0;
        int res;

        if (alice == 1)
            res = INT_MIN;
        else
            res = INT_MAX;

        for (int X = 1; X <= 2 * M; X++) {
            if (i + X - 1 >= piles.size()) {
                break;
            }

            total += piles[i + X - 1];

            if (alice == 1) {
                // Alice maximizes her score
                res = max(res, total + helper(i + X, 0, piles, max(M, X), memo));
            } else {
                // not substracting as we dont want the diff i.e ALICE-BOB instead we only want
                // Alice Score
                res = min(res, helper(i + X, 1, piles, max(M, X), memo));
            }
        }
        return memo[alice][i][M] = res;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> memo(2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return helper(0, 1, piles, 1, memo);
    }
};
