class Solution {
public:
    int minAddToMakeValid(string s) {
        int counter = 0;
  		stack<char> stack;
  		
        for(int i = 0; i < s.length(); i++) {
  			if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
  				stack.push(s[i]);
  			}
  			else if(!stack.empty()) {
  				if((s[i] == ')' && stack.top() == '(') || (s[i] == '}' && stack.top() == '{') || (s[i] == ']' && stack.top() == '[')) {
  					stack.pop();
  				}
  				else {
  					counter++;
  				} 
  			} 
            else {
                counter++;
            }
  		}      

  		if(!stack.empty()) {
  			counter += stack.size();
  		}
        
  		return counter;    
    }
};