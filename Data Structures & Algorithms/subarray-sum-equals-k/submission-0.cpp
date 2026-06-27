class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int currSum = 0;
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;

        for (int num : nums) {
            currSum += num;
            int diff = currSum - k;

            if (prefixSums.find(diff) != prefixSums.end()) {
                res += prefixSums[diff];
            }

            prefixSums[currSum]++;
        }

        return res;
    }
};