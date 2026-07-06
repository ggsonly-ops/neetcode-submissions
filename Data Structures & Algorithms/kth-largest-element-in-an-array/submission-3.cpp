
class Solution {
public:
    // Function to get the Kth largest element 
     int findKthLargest(vector<int>& nums, int k) {
        // Return -1, if the Kth largest element does not exist
        if(k > nums.size()) return -1;
        
        // Pointers to mark the part of working array 
        int left = 0, right = nums.size() - 1;
        
        // Until the Kth largest element is found
        while(true) {
            // Get the pivot index
            int pivotIndex = randomIndex(left, right);
            
            // Update the pivotIndex
            pivotIndex = partitionAndReturnIndex(nums, pivotIndex, left, right);
            
            // If Kth largest element is found, return
            if(pivotIndex == k-1) return nums[pivotIndex];
            
            // Else adjust the end pointers in array 
            else if(pivotIndex > k-1) right = pivotIndex - 1;
            else left = pivotIndex + 1;
        }
        
        return -1;
    }
    
private:
    // Function to get a random index 
    int randomIndex(int &left, int &right) {
        // length of the array 
        int len = right - left + 1;
        
        // Return a random index from the array 
        return (rand() % len) + left;
    }
    
    // Function to perform the partition and return the updated index of pivot
    int partitionAndReturnIndex(vector<int> &nums, int pivotIndex, int left, int right) {
        int pivot = nums[pivotIndex]; // Get the pivot element
        
        // Swap the pivot with the left element
        swap(nums[left], nums[pivotIndex]);
        
        int ind = left + 1; // Index to mark the start of right portion
        
        // Traverse on the array 
        for(int i = left + 1; i <= right; i++) {
            
            // If the current element is greater than the pivot
            if(nums[i] > pivot) {
                // Place the current element in the left portion
                swap(nums[ind], nums[i]);
                
                // Move the right portion index
                ind++;
            }
        }
        
        swap(nums[left], nums[ind-1]); // Place the pivot at the correct index
        
        return ind-1; // Return the index of pivot now
    }
};