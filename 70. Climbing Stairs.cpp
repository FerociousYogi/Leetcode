class Solution {
public:
    int helper(vector<int>& ways, int n) {
        if(ways[n] != 0) {
            return ways[n];
        }
        else if(n <= 1) {
            ways[n] = 1;
        }
        else {
            ways[n] = helper(ways, n-1) + helper(ways, n-2);
        }
        return ways[n];
    }
    
    
    int climbStairs(int n) {
        vector<int> ways(n+1, 0);
        return helper(ways, n);
    }
};