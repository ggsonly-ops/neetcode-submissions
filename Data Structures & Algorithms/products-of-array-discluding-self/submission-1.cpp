class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Pass 1: Compute running prefix products directly into ans
        // ans[i] will store the product of all elements to the left of index i
        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = leftProduct;
            leftProduct *= nums[i];
        }

        // Pass 2: Compute running suffix products and multiply on the fly
        // rightProduct maintains the accumulated product of all elements to the right of index i
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return ans;
    }
};
