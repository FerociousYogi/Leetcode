class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if(s.length() == 12) {
            string t = "";
            for(int i = 0; i < 4; i++) {
            	t += s.substr(3*i, 3);
            	t += ".";
            }
            ret.push_back(t);
            
            return ret;
        }
        else {
        	
        }
    }
};