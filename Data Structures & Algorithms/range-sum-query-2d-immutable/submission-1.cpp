class NumMatrix {
private:
    // Declare the prefix matrix as a class member variable so sumRegion can access it
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        // 🚀 Size it to (n+1) x (m+1) initialized to 0. This completely eliminates boundary checks!
        prefix.assign(n + 1, vector<int>(m + 1, 0));

        // Build the 2D prefix sum grid
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefix[i][j] = matrix[i - 1][j - 1] 
                             + prefix[i - 1][j] 
                             + prefix[i][j - 1] 
                             - prefix[i - 1][j - 1]; // Subtract the overlap double-count
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Shift indices by +1 to match our padded prefix matrix mapping
        return prefix[row2 + 1][col2 + 1] 
             - prefix[row1][col2 + 1] 
             - prefix[row2 + 1][col1] 
             + prefix[row1][col1]; // Re-add the overlap region we subtracted twice
    }
};
