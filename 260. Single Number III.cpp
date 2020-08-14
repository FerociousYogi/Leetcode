class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // With bit manipulation.
        // 1) get sum of two non-repeating elements.
        int sum = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // 2) get first rightmost set-bit and set everything else to zero. this is where the two-numbers start to differ.
        sum &= -sum;
        // 3) separate the bits into two parts. all duplicate nums will cancel out with XOR operation. 
        vector<int> result = {0, 0};
        for (auto &num : nums) {
            if ((num & sum) == 0) result[0] ^= num;   // not set.
            else result[1] ^= num;  // bit is set.
        }
        
        return result;
    }
};