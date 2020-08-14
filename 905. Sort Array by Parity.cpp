class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even, odd;
        for(auto x : A) {
            if(x % 2 == 0) {
                even.push_back(x);
            }
            else {
                odd.push_back(x);
            }
        }
        
        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }
};


// Another solution that is inplace

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0; int r = A.size() - 1;
        while(l < r) {
            if(A[l] % 2 == 1) {
                swap(A[l], A[r--]);
            }
            else {
                l++;
            }
        }
        return A;
    }
};