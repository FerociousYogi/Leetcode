class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) {
            return 0;
        }
        int length = s.length();
        set<char> set;
        int i = 0, j = 0, ans = 0;
        
        while(i < length && j < length) {
            if(!set.count(s[j])) {
                set.insert(s[j++]);
                ans = max(ans, j-i);
            }
            else {
                set.erase(s[i++]);
            }
        }
        
        return ans;
    }
};