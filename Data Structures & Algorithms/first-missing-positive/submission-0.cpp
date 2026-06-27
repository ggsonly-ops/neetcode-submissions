class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();

        // Step 1: Clean the array.
        // The answer must fall strictly within the range [1, n + 1].
        // Any number <= 0 or > n is noise, so we replace it with a safe placeholder (n + 1).
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Step 2: Mark the presence of valid integers in-place.
        // We treat the indices [0, n-1] as our hash map slots representing numbers [1, n].
        // If we see a value 'num', we flip the sign of the element at index (num - 1) to negative.
        for (int i = 0; i < n; i++) {
            // Use std::abs because the element at the current index might have already been flipped negative
            int num = std::abs(nums[i]);
            
            // If it's our placeholder (n + 1), it doesn't map to an index, so skip it
            if (num > n) continue;

            // Map the value 'num' to index 'num - 1'. If it's positive, flip it to negative.
            if (nums[num - 1] > 0) {
                nums[num - 1] = -nums[num - 1];
            }
        }

        // Step 3: Find the first missing positive integer.
        // Walk through the array. The first index 'i' containing a positive number 
        // means the integer value (i + 1) was never encountered in Step 2.
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        // Base Case: If the array is perfectly filled from 1 to n, then n + 1 is missing.
        return n + 1;
    }
};
