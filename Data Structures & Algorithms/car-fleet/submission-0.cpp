class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car;
        for(int i=0;i<position.size();i++){
            car.push_back({position[i],speed[i]});
        }
        sort(car.begin(),car.end());
        stack<double> st;
        for(int i=car.size()-1;i>=0;i--){
            double time=(double)(target-car[i].first)/car[i].second;
            if(st.empty() || time>st.top() ){
                st.push(time);
            }
        }
        return st.size();
    }
};
