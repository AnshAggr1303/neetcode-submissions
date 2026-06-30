class Solution {
public:
    int maxArea(vector<int>& heights) {
        int lp=0;int rp=heights.size()-1;
        int maxwater=0;
        while(lp<rp){
            int w=rp-lp;
            int h= min(heights[lp],heights[rp]);
            int currentwater= w*h;
            maxwater=max(maxwater, currentwater);
            heights[lp]<heights[rp] ? lp++ : rp--;
        }
        return maxwater;
    }
};
