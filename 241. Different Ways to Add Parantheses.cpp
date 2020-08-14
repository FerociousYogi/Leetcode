// Resursion solution

class Solution {
public:
    int convert(string num) {
        int ret = 0;
        for (int i = 0; i < num.length(); i++) {
            ret = (ret * 10) + (num[i] - '0');
        }
        
        return ret;
    }
    
    vector<string> tokenise(string input) {
        vector<string> ret;
        
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '+' || input[i] == '*' || input[i] == '-') {
                string temp = "";
                temp += input[i];
                ret.push_back(temp);
            }
            else {
                string temp = "";
                while (i < input.length() && !(input[i] == '+' || input[i] == '*' || input[i] == '-')) {
                    temp += input[i];
                    i++;
                }
                ret.push_back(temp);
                i--;
            }
        }
        
        return ret;
    }
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        vector<string> tokens = tokenise(input);
        
        for (auto x : tokens) {
            cout << x << endl;
        }
        cout << "-------------" << endl;
        
        if (tokens.size() == 0) {
            ret.push_back(0);
            return ret;
        }
        else if (tokens.size() == 1) {
            ret.push_back(convert(tokens[0]));
            return ret;
        }
        
        
        for (int i = 0; i < tokens.size(); i += 2) {
            if (i == tokens.size() - 1) break;
            
            int length = 0;
            for (int ii = 0; ii <= i; ii++) {
                length += tokens[ii].length();
            }
            
            vector<int> left = diffWaysToCompute(input.substr(0, length));
            vector<int> right = diffWaysToCompute(input.substr(length+1));
            
            for (auto x : left) {
                for (auto y : right) {
                    if (tokens[i+1]  == "+") {
                        ret.push_back(x + y);
                    } 
                     else if (tokens[i+1] == "*") {
                        ret.push_back(x * y);
                    }
                    else if (tokens[i+1] == "-") {
                        ret.push_back(x - y);
                    }
                    else {
                        cout << "Incorrect" << endl;
                    }
                }
            }
        }
        
        return ret;
    }
};