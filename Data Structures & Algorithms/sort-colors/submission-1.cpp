class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;                  // Indicates where the next '0' goes
        int high = nums.size() - 1;   // Indicates where the next '2' goes
        int mid = 0;                  // Your active scanner pointer

        // Keep scanning until the scanner crosses the '2' boundary
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Shift 0 to the front
                swap(nums[mid], nums[low]);
                low++;
                mid++; // Safe to move scanner because low only holds 0s or 1s
            } 
            else if (nums[mid] == 2) {
                // Shift 2 to the back
                swap(nums[mid], nums[high]);
                high--;
                // CRITICAL: Do NOT do mid++ here!
                // Inspect the swapped element next. as 
                //it maybe a 0 which needs to be moved to the start of the arr
            } 
            else {
                // It's a 1! Leave it alone and just move the scanner forward
                mid++;
            }
        }
    }
};
