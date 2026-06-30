class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int &n, int k,int start,vector<int>& curr){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<=n;i++){ //basically this is the template of backtracking
            curr.push_back(i);
            dfs(n,k,i+1,curr);

            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        dfs(n,k,1,curr);
        return ans;
    }
};