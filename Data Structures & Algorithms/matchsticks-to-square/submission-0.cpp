class Solution {
public:

    bool dfs(vector<int>& sticks,vector<int>& sides,int index,int target){
        if(index == sticks.size()){
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;
        }
        int stick = sticks[index];
        for(int i=0;i<4;i++){
            if(sides[i] + stick > target)//1+2>2
                continue;
            sides[i] += stick; //backtraking template add
            if(dfs(sticks,sides,index+1,target))//explore
                return true;
            sides[i] -= stick;//backtrack
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int x : matchsticks)
            sum += x;
        if(sum % 4 != 0)
            return false;
        int target = sum / 4;
        sort(matchsticks.rbegin(),matchsticks.rend());//imp r in sort wrna time limit exceed
        vector<int> sides(4,0);
        return dfs(matchsticks,sides,0,target);
    }
};