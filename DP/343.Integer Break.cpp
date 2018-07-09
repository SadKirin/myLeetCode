class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        
        dp[0] = 0;
        dp[1] = 1;
        //dp[2] = 1;
        for(int i = 2; i <= n; ++i){
            //把绳子分为 j 和 i-j 两部分
            for(int j = 1; j < i; ++j){
                dp[i] = max(dp[i],max(j * dp[i-j], j * (i-j)));
            }
        }
        return dp[n];
        
    }
};