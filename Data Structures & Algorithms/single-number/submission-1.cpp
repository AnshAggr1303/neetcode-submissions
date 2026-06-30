class Solution {
public:
    int singleNumber(vector<int>& nums) { 
        int ans = 0 ; //val of xor
        for(int num: nums){
            ans ^= num;
        }

        return ans;
    }
};