class Solution {
   private:
    bool dfs(int row, int col, int idx, vector<vector<char>>& board, string& word,
             vector<vector<bool>>& vis, int n, int m) {

        if (idx == word.size()) return true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int dir = 0; dir < 4; dir++) {
            int newRow = row + dr[dir];
            int newCol = col + dc[dir];

            if ( newRow >= 0 && newRow < n && newCol >= 0 &&
                newCol < m && board[newRow][newCol] == word[idx]  && !vis[newRow][newCol]) {
                // process (newRow, newCol)
                vis[newRow][newCol] = true;
                if (dfs(newRow, newCol, idx + 1, board, word, vis, n, m)) return true;
                vis[newRow][newCol] = false;
            }
        }
        return false;
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vis[i][j]=true;
                    if(dfs(i,j,1,board,word,vis,n,m)) return true;
                    vis[i][j]=false;
                }
            }
        }
        return false;
    }
};
