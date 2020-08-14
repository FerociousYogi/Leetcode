class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            }
            else if(!stack.empty()) {
                if(s[i] == ')') {
                    if(stack.top() == '(') stack.pop();
                    else return false;
                }
                else if(s[i] == '}') {
                    if(stack.top() == '{') stack.pop();
                    else return false;
                }
                else if(s[i] == ']') {
                    if(stack.top() == '[') stack.pop();
                    else return false;
                }   
            }
            else {
                cout << "Invalid String" << endl;
                return false;
            }
        }
        
        if(!stack.empty()) return false;
        
        return true;
    }
};