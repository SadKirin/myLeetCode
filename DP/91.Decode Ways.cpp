class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        
        if(len <= 0)
            return 0;
        vector<int> dp(len,0);
        dp[0] = s[0] != '0' ? 1 : 0;
        dp[1] = (s[0] != '0' && s[1] != '0' ? 1 : 0) + (s[0] != '0' && (((s[0] - '0') * 10 + s[1] - '0') <= 26) ? 1 : 0);
        
        
        for(int i = 2; i < len; ++i){
            if(s[i] != '0')
                dp[i] += dp[i-1];
            if(s[i-1] != '0' && (((s[i-1] - '0') * 10 + s[i] - '0') <= 26))
                dp[i] += dp[i-2];
        }
        
        return dp[len - 1];
    }
};