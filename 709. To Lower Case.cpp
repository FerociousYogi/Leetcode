class Solution {
public:
    string toLowerCase(string str) {
        string ret = "";
        int length = str.length();
        for(int i = 0; i < length; i++) {
        	if(str[i] < 97 && str[i] >= 65) {
        		ret += (str[i] + 32);
        	}
        	else {
        		ret += str[i];
        	}
        }
        return ret;
    }
};