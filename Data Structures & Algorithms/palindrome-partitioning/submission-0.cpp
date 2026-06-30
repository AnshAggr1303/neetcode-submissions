class Solution {
public:

    vector<vector<string>> ans;

    bool isPalindrome(string& s,int left,int right){
        while(left < right){
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }

        return true;
    }

    void dfs(string& s,int start,vector<string>& partition){
        if(start == s.size()){
            ans.push_back(partition);
            return;
        }

        for(int end = start;end < s.size();end++){
            if(isPalindrome(s,start,end)){
                partition.push_back( s.substr(start,end-start+1));
                dfs(s,end+1,partition);
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> partition;
        dfs(s,0,partition);
        return ans;
    }
};