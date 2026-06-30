class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> map;
        for(int num:nums){
            map[num]++;
        }
        for(int i=0;i<k;i++){
            int maxfreq=0;
            int element;
            for(auto x:map){
                if(x.second>maxfreq){
                    maxfreq=x.second;
                    element=x.first;
                }
            }
            ans.push_back(element);
            map[element]=0;
        }
        return ans;
        
    }
};