class Solution {
public:

    bool dfs(vector<int>& nums,vector<int>& buckets,int index,int target){
        if(index == nums.size())
            return true;
        int num = nums[index];
        for(int i=0;i<buckets.size();i++){
            if(buckets[i] + num > target)
                continue;

            buckets[i] += num;//bactracking template
            if(dfs(nums,buckets,index + 1,target))
                return true;
            buckets[i] -= num;

            // Optimization:
            // don't try other empty buckets
            if(buckets[i] == 0)
                break;
        }

        return false;
    }

    bool canPartitionKSubsets(
        vector<int>& nums,int k) {
        int sum = 0;
        for(int x : nums)
            sum += x;

        if(sum % k != 0)
            return false;
        int target = sum / k;
        sort(nums.rbegin(),nums.rend());//imp r
        vector<int> buckets(k,0);
        return dfs(nums,buckets,0,target);
    }
};