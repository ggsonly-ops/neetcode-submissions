#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        vector<char> st; // Using vector as a stack

        for (int i = 0; i < s.size(); i++) {
            // 1. If it's not a closing bracket, push it to the stack (including '[')
            if (s[i] != ']') {
                st.push_back(s[i]);
            } 
            // 2. When we hit ']', process the encoded segment
            else {
                string str = "";
                
                // Get all the characters until we reach the matching '['
                while (!st.empty() && st.back() != '[') {
                    str += st.back();
                    st.pop_back();
                }
                st.pop_back(); // Pop the opening bracket '[' out of the stack
                reverse(str.begin(), str.end()); // Reverse because stack flips order

                string digit = "";
                // Get the complete multi-digit number before the '['
                while (!st.empty() && isdigit(st.back())) {
                    digit += st.back();
                    st.pop_back();
                }
                reverse(digit.begin(), digit.end()); // Reverse the digit characters
                
                int dig = stoi(digit); // Convert string to integer
                
                // C++ equivalent of python's "str * dig"
                string repeated_str = "";
                for (int j = 0; j < dig; j++) {
                    repeated_str += str;
                }

                // Push the newly formed decoded string back onto the stack character by character
                for (char c : repeated_str) {
                    st.push_back(c);
                }
            }
        }

        // 3. Rebuild the final string from the remaining characters in the stack
        string result = "";
        for (char c : st) {
            result += c;
        }
        
        return result;
    }
};
