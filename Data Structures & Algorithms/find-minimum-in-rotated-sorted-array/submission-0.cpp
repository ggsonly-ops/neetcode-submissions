class Solution {
public:
    /* Function to find minimum element
    in a rotated sorted array */
    int findMin(vector<int>& arr) {
        
        // Initialize low and high indices
        int low = 0, high = arr.size() - 1; 
        
        // Initialize ans to maximum integer value
        int ans = INT_MAX;  
        while (low <= high) { 
            int mid = (low + high) / 2; 

            // Check if left part is sorted
            if (arr[low] <= arr[mid]) {
                
                /* Update ans with minimum 
                of ans and arr[low] */
                ans = min(ans, arr[low]);  
                
                // Move to the right part
                low = mid + 1;  
            } 
            else {  
                /* Update ans with minimum 
                of ans and arr[mid] */
                ans = min(ans, arr[mid]);  
                
                // Move to the left part
                high = mid - 1;  
            }
        }
        // Return the minimum element found
        return ans; 
    }
};