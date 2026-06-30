class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int,char>> pq;

        if(a > 0) pq.push({a,'a'});
        if(b > 0) pq.push({b,'b'});
        if(c > 0) pq.push({c,'c'});

        string ans;

        while(!pq.empty()) {

            auto [freq1, ch1] = pq.top();
            pq.pop();

            // Would this create xxx ?
            if(ans.size() >= 2 &&
               ans.back() == ch1 &&
               ans[ans.size()-2] == ch1) {

                // No second option available
                if(pq.empty())
                    break;

                auto [freq2, ch2] = pq.top();
                pq.pop();

                ans += ch2;
                freq2--;

                if(freq2 > 0)
                    pq.push({freq2, ch2});

                // Put first choice back
                pq.push({freq1, ch1});
            }
            else {

                ans += ch1;
                freq1--;

                if(freq1 > 0)
                    pq.push({freq1, ch1});
            }
        }

        return ans;
    }
};