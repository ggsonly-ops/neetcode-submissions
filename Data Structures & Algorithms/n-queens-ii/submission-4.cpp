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


    void helper(int row, int& count, vector<string> &board) {
        if (row == board.size()) {
            count++;
            return;
        }

        for (int col = 0; col < board[0].size(); col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                helper(row + 1, count, board); 
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));

       
        int count = 0;

        helper(0, count, board);

        return count;
    }
};