class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";
        if(n == 1) return "1";
        
        string prev = "1";
        string curr = prev;
        
        for(int i = 2; i <= n; i++) {
            curr.clear();
            for(int j = 0; j < prev.length(); j++) {
                int count = 1;
                while(j+1 < prev.length() && prev[j+1] == prev[j]) {
                    j++;
                    count++;
                }
                curr.append(to_string(count) + prev[j]);
            }
            prev = curr;
        }
        return curr;
    }
};