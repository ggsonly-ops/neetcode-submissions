class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid, 0, 0, n);
    }

private:
    bool isUniform(vector<vector<int>>& grid, int row, int col, int n) {
        int first = grid[row][col];
        for (int i = row; i < row + n; i++) {
            for (int j = col; j < col + n; j++) {
                if (grid[i][j] != first) return false;
            }
        }
        return true;
    }

    Node* build(vector<vector<int>>& grid, int row, int col, int n) {
        if (isUniform(grid, row, col, n)) {
            return new Node(grid[row][col], true, nullptr, nullptr, nullptr, nullptr);
        }

        int h = n / 2;
        Node* topLeft    = build(grid, row,     col,     h);
        Node* topRight   = build(grid, row,     col + h, h);
        Node* bottomLeft = build(grid, row + h, col,     h);
        Node* bottomRight= build(grid, row + h, col + h, h);

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};