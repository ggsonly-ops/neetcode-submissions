class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        // dp[i] = the maxVal/minVal of all the subarrays that can end at index i

        int n = nums.size();
        vector<int> maxValDP(n);
        vector<int> minValDP(n);

        maxValDP[0] = nums[0];
        minValDP[0] = nums[0];
        int res=maxValDP[0];


        for (int i = 1; i < n; i++) {
            maxValDP[i] = max({nums[i], maxValDP[i - 1] * nums[i], minValDP[i - 1] * nums[i]});
            minValDP[i] = min({nums[i], maxValDP[i - 1] * nums[i], minValDP[i - 1] * nums[i]});
            res=max(res,maxValDP[i]);
        }
        return res;
    }
};
