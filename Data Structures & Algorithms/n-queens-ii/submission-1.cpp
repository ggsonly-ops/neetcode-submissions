class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col) {
        int r = row, c = col;

        // Check for upper left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        // Reset to the original position
        r = row;
        c = col;

        // Check for top
        while (r >= 0) {
            if (board[r][c] == 'Q') return false;
            r--;
        }

        // Reset to the original position
        r = row;
        c = col;

        // Check for top right diagonal
        while (r >= 0 && c < board[0].size()) {
            if (board[r][c] == 'Q') return false;
            r--;
            c++;
        }

        return true;
    }

    // CHANGE 1: signature changed from (int row, vector<vector<string>>& ans, vector<string>& board)
    // to (int row, int& count, vector<string>& board) -- we no longer need to collect every
    // full board into a vector<vector<string>>, since totalNQueens only needs the COUNT of
    // valid solutions, not the boards themselves.
    void helper(int row, int& count, vector<string> &board) {
        if (row == board.size()) {
            // CHANGE 2: replaced `ans.push_back(board)` (which copies the entire O(N) board,
            // costing O(N^2) per solution found) with a simple `count++` (O(1)), since we
            // only care about how many valid solutions exist, not what they look like.
            count++;
            return;
        }

        for (int col = 0; col < board[0].size(); col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                helper(row + 1, count, board); // CHANGE 3: pass `count` through instead of `ans`
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        // CHANGE 4: removed `vector<vector<string>> ans;` entirely -- no longer needed,
        // since we're not storing board layouts anymore.
        vector<string> board(n, string(n, '.'));

        // CHANGE 5: added `int count = 0;` to track the number of valid solutions directly.
        int count = 0;

        helper(0, count, board);

        // CHANGE 6: return `count` directly instead of `ans.size()`.
        return count;
    }
};