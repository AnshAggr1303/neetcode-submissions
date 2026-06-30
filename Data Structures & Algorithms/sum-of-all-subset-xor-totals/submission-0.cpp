class Solution {
public:

    int dfs(vector<int>& nums, int index, int currXor) {
        // One complete subset formed
        if(index == nums.size()) {
            return currXor;
        }
        // Include current element
        int take =
            dfs(nums,index + 1,currXor ^ nums[index]);

        // Exclude current element
        int skip =
            dfs(nums,index + 1,currXor);

        return take + skip;
    }

    int subsetXORSum(vector<int>& nums) {

        return dfs(nums, 0, 0);
    }
};