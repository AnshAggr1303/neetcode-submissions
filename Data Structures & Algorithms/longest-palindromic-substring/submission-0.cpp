class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int maxlen=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            //odd len
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxlen){
                    maxlen=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
            //even len
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxlen){
                    maxlen=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
        }
        return s.substr(start,maxlen);
    }
};