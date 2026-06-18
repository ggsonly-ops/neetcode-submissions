

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        // Use unsigned int to handle potential LeetCode integer overflow cases safely
        std::vector<unsigned int> dp(target + 1, 0);
        
        // Base case: There is 1 way to form a target of 0 (using an empty set)
        dp[0] = 1;
        
        // Outer loop moves through targets so order/permutation of numbers matters
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
};
