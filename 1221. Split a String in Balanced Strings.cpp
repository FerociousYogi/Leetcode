class Solution {
public:
    int balancedStringSplit(string s) {
    	int counter = 0;
    	int L = 0, R = 0;
    	for(int i = 0; i < s.length(); i++) {
    		if(s[i] == 'L') {
    			L++;
    		}
    		else {
    			R++;
    		}
    		if(L == R) {
    			counter++;
    		}
    	}
    	return counter; 
    }
};