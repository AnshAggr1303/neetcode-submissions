class Solution {
public:
    int rob2(vector<int>& nums){
        int n = nums.size();
        if(n == 1)
            return nums[0]; //here also
        nums[1] = max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            nums[i] = max(nums[i-1],nums[i] + nums[i-2]); //template for dp
        }
        return nums[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0]; //alright this is also important if there is n==1
        }
        vector<int> first(nums.begin(),nums.end()-1); //main logic diff from house robber
        vector<int> second(nums.begin()+1,nums.end());//this line also

        return max(rob2(first),rob2(second));
    }
};