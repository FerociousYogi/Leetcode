class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        
        if (strs.size() == 0) return ret;
        
        for(int c = 0; c < strs[0].length(); c++) {
            if (strs[0].length() == 0) {
                return ret;
            }
            char ch = strs[0][c];
            bool poss = true;
            
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][c] != ch) {
                    poss = false;
                    break;
                }
            }
            
            if (poss) ret += ch;
            else return ret;
        }
        
        return ret;
    }
};