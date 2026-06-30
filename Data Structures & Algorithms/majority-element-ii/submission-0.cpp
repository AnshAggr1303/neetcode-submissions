class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans ;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        for(auto x:map){
            if(x.second>n/3){
                ans.push_back(x.first);
            }
        }
        return ans ;
    }
};