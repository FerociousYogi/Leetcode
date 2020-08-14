class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        
        bool flag = true;
        map<char, char> m;
        int len = s.length();
        
        for(int i = 0; i < len; i++) {
            if(m.find(s[i]) == m.end()) {
                m[s[i]] = t[i];
            }
            else {
                if(m[s[i]] != t[i]) {
                    flag = false;
                    break;
                }
            }
        }
        
        if(!flag) return false;
        
        flag = true;
        m.clear();
        
        for(int i = 0; i < len; i++) {
            if(m.find(t[i]) == m.end()) {
                m[t[i]] = s[i];
            }
            else {
                if(m[t[i]] != s[i]) {
                    flag = false;
                    break;
                }
            }
        }
        
        return flag;
    }
};