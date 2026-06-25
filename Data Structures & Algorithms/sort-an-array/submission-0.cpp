class Solution {
   public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++) L[i] = nums[left + i];
        for (int j = 0; j < n2; j++) R[j] = nums[mid + 1 + j];

        int curr = left;
        int l = 0;
        int r = 0;

        while (l < n1 && r < n2) {
            if (L[l] <= R[r]) {
                nums[curr] = L[l];
                l++;
            } else {
                nums[curr] = R[r];
                r++;
            }
            curr++;
        }

        while (l < n1) {
            nums[curr] = L[l];
            l++;
            curr++;
        }

        while (r < n2) {
            nums[curr] = R[r];
            r++;
            curr++;
        }
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }

    // MERGE SORT
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};