class Solution {
    vector<vector<int>> ans;
public:
    void solve(vector<int>& nums , int start, vector<int>& subset){
        ans.push_back(subset);
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            subset.push_back(nums[i]);
            solve(nums,i+1,subset);
            subset.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        solve(nums,0,subset);
        return ans;
    }
};