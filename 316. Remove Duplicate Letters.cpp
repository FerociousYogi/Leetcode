class Solution {
public:
    string removeDuplicateLetters(string s) {
  		vector<int> count(26, 0);
  		for(int i = 0; i < s.length(); i++) {
  			count[s[i] - 'a']++;
  		}  

  		unordered_set<char> charset;
  		stack<char> stack;

  		for(int i = 0; i < s.length(); i++) {
            char current = s[i];
            count[s[i] - 'a']--;
            
            if(charset.count(current)) continue;
            
            charset.insert(current);
            
  			if(stack.empty()) {
  				stack.push(s[i]);	
  			}
            else {
                while(!stack.empty() && stack.top() > current && count[stack.top() - 'a']) {
                    charset.erase(charset.find(stack.top()));
                    stack.pop();
                }
                stack.push(current);
            }
  		}
        
        string ret = "";
        while(!stack.empty()) {
            ret = stack.top() + ret;
            stack.pop();
        }        
        
        return ret;
    } 
};