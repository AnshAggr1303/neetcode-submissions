class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char,int> freq;

        // Count frequency of each character
        for(char ch : s){
            freq[ch]++;
        }

        // Max Heap -> {frequency, character}
        priority_queue<pair<int,char>> pq;

        for(auto& it : freq){
            pq.push({it.second, it.first});
        }

        string ans = "";

        int prevFreq = 0;
        char prevChar = '#';

        while(!pq.empty()) {

            // Get character with highest frequency
            auto [currFreq, currChar] = pq.top();
            pq.pop();

            // Add it to answer
            ans += currChar;

            // If previous character still has occurrences left,
            // put it back into heap now
            if(prevFreq > 0) {
                pq.push({prevFreq, prevChar});
            }

            // Current character goes on cooldown
            prevFreq = currFreq - 1;
            prevChar = currChar;
        }

        // If answer length is not same as original string,
        // rearrangement was impossible
        if(ans.size() != s.size()) {
            return "";
        }

        return ans;
    }
};