class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates,int target,int index,vector<int>& curr){
        if(target==0){ // means got answer 
            ans.push_back(curr);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){ // will remove dulpicates
                continue;
            } 
            //take
            curr.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i+1,curr); //subtract from target

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,int target) {
        sort(candidates.begin(), candidates.end()); //sort imp to remove duplicates
        vector<int> curr;
        dfs(candidates,target, 0, curr);
        return ans;
    }
};