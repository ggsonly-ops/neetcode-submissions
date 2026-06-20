class Solution {
public:
    // memo[i][j] will store: -1 for unvisited, 0 for false, 1 for true
    vector<vector<int>> memo;

    bool helper(int i, int j, const string& s, const string& p) {
        // Base Case 1: If we reached the end of the pattern, 
        // we must also be at the end of the string to have a match.
        if (j == p.size()) return i == s.size();

        // Check memo table to avoid recalculating
        if (memo[i][j] != -1) return memo[i][j];

        // Check if the current characters match directly
        bool current_match = (i < s.size() && (p[j] == s[i] || p[j] == '.'));

        bool ans = false;
        
        // Look ahead: Is the NEXT character a star?
        if (j + 1 < p.size() && p[j + 1] == '*') {
            // Choice 1: Don't use the star (skip 2 pattern characters)
            bool skip_star = helper(i, j + 2, s, p);
            
            // Choice 2: Use the star (consume 1 string character if it matches)
            bool use_star = current_match && helper(i + 1, j, s, p);
            
            ans = skip_star || use_star;
        } else {
            // No star ahead: Just move forward 1-to-1 if they match
            ans = current_match && helper(i + 1, j + 1, s, p);
        }

        return memo[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        // Size needs to be (n + 1) x (m + 1) to handle the out-of-bounds base cases safely
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return helper(0, 0, s, p);
    }
};
