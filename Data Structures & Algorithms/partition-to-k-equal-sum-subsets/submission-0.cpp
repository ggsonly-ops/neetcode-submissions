class Solution {
private:
    bool backtrack(vector<int>& nums, int idx, vector<int>& buckets, int target) {
        if (idx == nums.size()) {
            // all elements placed -- since we only ever add when it fits within target,
            // and total sum == k * target, every bucket must equal target by now
            return true;
        }

        for (int b = 0; b < buckets.size(); b++) {
            if (buckets[b] + nums[idx] <= target) {
                buckets[b] += nums[idx];
                if (backtrack(nums, idx + 1, buckets, target)) return true;
                buckets[b] -= nums[idx];
            }

            // optimization: if this bucket is currently empty and this placement failed,
            // no other empty bucket will succeed either -- skip trying more empty buckets
            if (buckets[b] == 0) break;
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int n : nums) sum += n;

        if (sum % k != 0) return false;
        int target = sum / k;

        // sorting largest-first helps prune bad branches earlier
        sort(nums.rbegin(), nums.rend());

        // if the largest single element already exceeds target, impossible
        if (nums[0] > target) return false;

        vector<int> buckets(k, 0);
        return backtrack(nums, 0, buckets, target);
    }
};