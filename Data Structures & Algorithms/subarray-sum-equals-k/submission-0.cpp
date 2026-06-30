class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]=1;
        int prefixsum=0;
        int count=0;
        for(int num:nums){
            prefixsum+=num;
            if(map.find(prefixsum-k)!=map.end()){
                count+=map[prefixsum-k];
            }
            map[prefixsum]++;
        }
        return count;
    }
};