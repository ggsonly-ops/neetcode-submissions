class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        // Kadane's trackers for the MAXIMUM (non-circular) subarray sum
        int currSum = nums[0]; // best sum of a subarray ending at the current index
        int maxSum = nums[0];  // best sum seen anywhere so far

        // Kadane's trackers for the MINIMUM (non-circular) subarray sum
        // -- used to find the worst "middle chunk" to exclude for the circular case
        int currMin = nums[0]; // worst (most negative) sum of a subarray ending at the current index
        int minSum = nums[0];  // worst sum seen anywhere so far

        // Running total of the entire array -- needed to compute the
        // circular-wrap answer as (totalSum - excludedMiddleSum)
        int totalSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            // Standard Kadane's step: either extend the previous run by
            // adding nums[i], or start a fresh subarray at nums[i] alone --
            // whichever gives the larger sum
            currSum = max(currSum + nums[i], nums[i]);
            maxSum = max(currSum, maxSum);

            // Mirror of the above, but hunting for the MINIMUM sum instead:
            // either extend the previous negative run, or restart at nums[i]
            // alone -- whichever gives the smaller (more negative) sum
            currMin = min(currMin + nums[i], nums[i]);
            minSum = min(currMin, minSum);

            totalSum += nums[i];
        }

        // Edge case: if every element is negative, the "minimum subarray"
        // ends up being the ENTIRE array, which would make
        // (totalSum - minSum) evaluate to 0 -- representing an empty
        // selection, which isn't a valid non-empty subarray.
        // In this case, just fall back to the plain (non-circular) Kadane's
        // answer, which correctly returns the single least-negative element.
        if (maxSum < 0) return maxSum;

        // Otherwise, the answer is the better of:
        //  1) maxSum        -> best subarray that does NOT wrap around
        //  2) totalSum - minSum -> best subarray that DOES wrap around,
        //                          found by excluding the most negative
        //                          possible contiguous "middle chunk"
        return max(maxSum, totalSum - minSum);
    }
};
