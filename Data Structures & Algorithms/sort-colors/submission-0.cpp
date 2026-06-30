class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0;int count1=0;int count2=0;
        for(int x:nums){
            if (x==0){
                count0++;
            }
            if (x==1){
                count1++;
            }
            if (x==2){
                count2++;
            }
        }
        int index=0;
        while(count0--){
            nums[index]=0;
            index++;
        }
        while(count1--){
            nums[index]=1;
            index++;
        }
        while(count2--){
            nums[index]=2;
            index++;
        }
    }
};