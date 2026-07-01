class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long add = n - 1;
        int bit = 0;
        while(add){
            // If this bit of x is 0, we can use it
            if((ans & (1LL << bit)) == 0){
                // If current bit of (n-1) is 1,
                // set this bit in ans
                if(add & 1){
                    ans |= (1LL << bit);
                }
                // Move to next bit of (n-1)
                add >>= 1;
            }
            bit++;
        }
        return ans;
    }
};