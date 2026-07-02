
class Solution {
   public:
    // Helper function: Checks how many subarrays are needed if the maximum 
    // allowed sum of any single subarray is capped at 'largestSum'.
    int numOfSubarrays(vector<int> &a, int largestSum) {
        int sum = 0;
        int count = 1; // Start with at least 1 subarray
        
        for (int val : a) {
            // Add the current element to our running subarray sum
            sum = sum + val;
            
            // If the sum exceeds the limit, we cannot include 'val' in the current subarray.
            // We must start a new subarray beginning with 'val'.
            if (sum > largestSum) {
                count++;    // Start a new subarray
                sum = val;  // Reset running sum to the current element's value
            }
        }
        return count;
    }
    int splitArray(vector<int>& a, int k) {
        // --- DEFINE THE BINARY SEARCH BOUNDS ---
        
        // 1. Lower Bound (low): The maximum single element in the array.
        //    Why? A subarray must contain at least one element. Therefore, the 
        //    minimized largest sum can never be smaller than the largest element.
        int low = *max_element(a.begin(), a.end());
        
        // 2. Upper Bound (high): The sum of all elements in the array.
        //    Why? If k = 1, we can't split the array, so the maximum sum is the 
        //    entire array's sum.
        int high = accumulate(a.begin(), a.end(), 0);
        
        // Initialize the answer with the maximum possible sum (worst case)
        int ans = high;
        // --- BINARY SEARCH ON ANSWER --- we are doing BS on sum
        while (low <= high) {
            // Find the middle sum limit to test
            int mid = low + (high - low) / 2;
            // Greedily count how many partitions are needed if the limit is 'mid'
            int partitions = numOfSubarrays(a, mid);
            // --- SHRINK THE SEARCH WINDOW ---
            
            if (partitions <= k) {
                // If we need 'k' or fewer partitions, then 'mid' is a VALID limit.
                // (If we need fewer than k, we can easily split them further to get exactly k).
                
                ans = mid;       // Record this as a potential answer
                high = mid - 1;  // Try to find a smaller valid sum limit (search left)
            } else {
                // If we need more than 'k' partitions, 'mid' is TOO SMALL.
                // We must increase the sum limit to allow fewer, larger partitions.
                
                low = mid + 1;   // Search right
            }
        }
        
        return ans;
    }
};




