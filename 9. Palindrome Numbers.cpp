// 1. Converting the integer to string

class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        string::size_type len = num.length();
        int i = 0;
        while(i <= len / 2) {
            if(num[i] != num[len - 1 - i]) {
                return false;
            }
            i++;
        }
        return true;
    }
};

// 2. Reversing the entire number:

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        long long reverse_int = 0;
        long long temp = x;
        
        while(temp) {
            reverse_int *= 10;
            reverse_int += (temp % 10);
            temp /= 10;
        }
        
        if(x == reverse_int) return true;
        
        return false;
    }
};

// 3. Reversing only the second half of the number:

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;
        
        int rev_half = 0;
        while(x > rev_half) {
            rev_half *= 10;
            rev_half += (x % 10);
            x /= 10;
        }
        
        cout << rev_half << endl;
        cout << x << endl;
        
        return rev_half == x || rev_half / 10 == x;
    }
};