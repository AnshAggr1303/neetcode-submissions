class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums,int index,vector<int> subset){
        if(index==nums.size()){
            ans.push_back(subset);
            return;
        }
        //take
        subset.push_back(nums[index]);
        dfs(nums,index+1,subset);
        //skip
        subset.pop_back();
        dfs(nums,index+1,subset);


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        dfs(nums,0,subset);
        return ans;
    }
};