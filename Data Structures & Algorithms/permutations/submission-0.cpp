class Solution {
    vector<vector<int>> ans;
public:
    void dfs(vector<int>& nums,int idx){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){ //backtracking template for permutation
            swap(nums[idx],nums[i]);
            dfs(nums,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return ans;
    }
};