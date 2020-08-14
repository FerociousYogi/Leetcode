// Solution 1:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int i = 0; int j = 0;
        while (i < matrix.size() && matrix[i][0] < target) i++;
        if (i < matrix.size() && matrix[i][0] == target) return true;
        
        i--;
        if (i < 0) return false;
        while (j < matrix[0].size() && matrix[i][j] < target) j++;
        
        if (j < matrix[0].size() && matrix[i][j] == target) return true;
        
        return false;
    }
};