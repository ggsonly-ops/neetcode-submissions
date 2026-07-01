class Solution {
private: 
    /* Function to match the opening 
    and closing brackets */
    bool isMatched(char open, char close) {
    
        // Match
        if((open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}')
        )
        return true;
        
        // Mismatch
        return false;
    }
   
public:
    /* Function to check if the 
    string is valid */
    bool isValid(string str) {
       
        // Initialize a stack
        stack<char> st;
        
        // Start iterating on the string
        for(int i=0; i < str.length(); i++) {
        
            // If an opening bracket is found
            if(str[i] == '(' || str[i] == '[' || 
               str[i] == '{') {
                // Push on top of stack
                st.push(str[i]);
            }
        
            // Else if a closing bracket is found
            else {
                // Return false if stack is empty
                if(st.empty()) return false;
                
                // Get the top elemenfrom stack
                char ch = st.top();
                st.pop();
                
                /* If the opening and closing brackets 
                are not matched, return false */
                if(!isMatched(ch, str[i])) 
                    return false;
            }
        }
        
        /* If stack is empty, the 
        string is valid, else invalid */
        return st.empty();
    }
};