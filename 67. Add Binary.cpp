class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        if(a.length() < b.length()) {
            a += string(b.length() - a.length(), '0');
        }
        else if(a.length() > b.length()) {
            b += string(a.length() - b.length(), '0');
        }
        
        string ret = "";
        
        int i = 0;
        int carry = 0;
        int len = a.length();
        
        while(i < len) {
            if(a[i] + b[i] + carry > 2 * '1') {
                ret += '1';
                carry = 1;
            }
            else if(a[i] + b[i] + carry == 2 * '1') {
                ret += '0';
                carry = 1;
            }
            else if(a[i] + b[i] + carry == '1' + '0') {
                ret += '1';
                carry = 0;
            }
            else {
                ret += '0';
                carry = 0;
            }
            
            i++;
        }
        
        if(carry) {
            ret += '1';
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};