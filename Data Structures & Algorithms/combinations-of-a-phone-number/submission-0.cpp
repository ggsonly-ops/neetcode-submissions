class Solution {
private:
    vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    }; // index 0,1 unused/empty since digits start at 2

    void backtrack(string& digits, int idx, string& curr, vector<string>& ans) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mapping[digits[idx] - '0'];
        for (char c : letters) {
            curr.push_back(c);
            backtrack(digits, idx + 1, curr, ans);
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans; // matches Example 2's expected output

        string curr;
        backtrack(digits, 0, curr, ans);
        return ans;
    }
};