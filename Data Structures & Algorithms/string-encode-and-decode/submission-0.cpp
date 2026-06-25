class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            // Pattern: [Length] + [#] + [String]
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    // Decodes a single string back to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        
        while (i < s.size()) {
            // 1. Find the position of the delimiter '#' starting from index i
            int hashPos = s.find('#', i);
            
            // 2. Extract the length string and convert it to an integer
            int len = stoi(s.substr(i, hashPos - i));
            
            // 3. Move the pointer past the '#' symbol
            i = hashPos + 1;
            
            // 4. Extract exactly 'len' characters as the original string
            decoded.push_back(s.substr(i, len));
            
            // 5. Jump the pointer forward by the length of the string
            i += len;
        }
        
        return decoded;
    }
};
