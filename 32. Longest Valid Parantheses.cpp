class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(), 0);
        int ret = 0;
        
        for(int i = 1; i < s.length(); i++) {
            if(dp[i-1] == 0 && s[i] == ')' && s[i-1] == '(') {
                dp[i] = 2;
                if(i - 2 >= 0) dp[i] += dp[i-2];
            }
            else if(dp[i-1] != 0 && s[i] == ')'){
                int len = dp[i-1];
                if(i - len - 1 >= 0 && s[i-len-1] == '(') {
                    dp[i] = len + 2;
                    if(i-len-2 >= 0) dp[i] += dp[i-len-2];
                }
            }

            ret = max(ret, dp[i]);
        }
        
        return ret;
    }
};

// There is also a O(n) solution that takes O(1) space using two pointers. Might implement later.