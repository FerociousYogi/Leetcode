class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m.insert({'I', 1});
        m.insert({'V', 5});
        m.insert({'X', 10});
        m.insert({'L', 50});
        m.insert({'C', 100});
        m.insert({'D', 500});
        m.insert({'M', 1000});
        
        int ret = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i+1 < s.length() && (s[i] == 'I' && s[i+1] == 'V')) {
                ret += 4;
                i++;
            }
            else if(i+1 < s.length() && (s[i] == 'I' && s[i+1] == 'X')) {
                ret += 9;
                i++;
            }
            else if(i+1 < s.length() && (s[i] == 'X' && s[i+1] == 'L')) {
                ret += 40;
                i++;
            }
            else if(i+1 < s.length() && (s[i] == 'X' && s[i+1] == 'C')) {
                ret += 90;
                i++;
            }
            else if(i+1 < s.length() && (s[i] == 'C' && s[i+1] == 'D')) {
                ret += 400;
                i++;
            }
            else if(i+1 < s.length() && (s[i] == 'C' && s[i+1] == 'M')) {
                ret += 900;
                i++;
            }
            else {
                ret += m[s[i]];
            }
        }
        
        return ret;
    }
};