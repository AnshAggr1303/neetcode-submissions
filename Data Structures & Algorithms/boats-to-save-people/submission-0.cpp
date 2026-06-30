class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int lp=0;int rp=n-1;
        int count=0;
        sort(people.begin(),people.end());
        while(lp<=rp){
            int sum=people[lp]+people[rp];
            if (sum<=limit){
                lp++;
            }
            rp--;
            count++;
        }
        return count;
        
    }
};