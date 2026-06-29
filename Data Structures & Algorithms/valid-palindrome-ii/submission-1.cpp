class Solution {
   public:
    bool isPalin(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return isPalin(s, l + 1, r) || isPalin(s, l, r - 1);
            l++;
            r--;
        }
        return true;
    }
};