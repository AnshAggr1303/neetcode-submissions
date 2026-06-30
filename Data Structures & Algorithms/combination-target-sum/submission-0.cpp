class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates,int target,int index,int currsum,vector<int>& combination){
        if(currsum==target){
            ans.push_back(combination);
            return;
        }
        if(currsum>target || index==candidates.size()){
            return;
        }
        combination.push_back(candidates[index]);
        dfs(candidates,target,index,currsum+candidates[index],combination);

        combination.pop_back();
        dfs(candidates,target,index+1,currsum,combination);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        dfs(candidates,target,0,0,combination);
        return ans;
    }
};