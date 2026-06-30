class Solution {
public:
    int characterReplacement(string s, int k) {
        int n =s.size();
        unordered_map<char,int> mp;
        int left=0,maxlen=0,maxfreq=0;
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            maxfreq=max(maxfreq,mp[s[right]]);
            //window size-maxfreq>k
            while((right-left+1)-maxfreq>k){
                mp[s[left]]--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};