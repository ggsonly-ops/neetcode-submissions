class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh_fruits = 0;
        int minutes = 0;

        // 1. Initialize queue with all rotten fruits and count fresh fruits
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    fresh_fruits++;
                }
            }
        }

        // If no fresh fruits exist initially, 0 minutes are needed
        if (fresh_fruits == 0) return 0;

        // Direction vectors for moving up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // 2. Process BFS level by level (minute by minute)
        while (!q.empty() && fresh_fruits > 0) {
            minutes++;
            int size = q.size();
            
            // Process all fruits rotting at the current minute
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    // Check boundaries and if the neighbor is a fresh fruit
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // Infect the fruit
                        fresh_fruits--;    // Decrement the fresh count
                        q.push({nr, nc});
                    }
                }
            }
        }

        return (fresh_fruits == 0) ? minutes : -1;
    }
};
