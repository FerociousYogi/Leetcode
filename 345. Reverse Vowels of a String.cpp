class Solution {
public:
    string reverseVowels(string s) {
        vector<int> indices;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int length = s.length();
        for(int i = 0; i < length; i++) {
            if(find(vowels.begin(), vowels.end(), s[i]) != vowels.end()) {
                indices.push_back(i);
            }
        }
        
        int n = indices.size();
        
        for(int i = 0; i < n/2; i++) {
            swap(s[indices[i]], s[indices[n-1-i]]);
        }
        
        return s;
    }
};