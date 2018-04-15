class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() <= 0)
            return 0;
        
        if(nums.size() == 1)
            return nums[0];
        int len = nums.size();
        vector<int> dp(len);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        //类似0、1背包问题
        for(int i = 2; i < len; ++i){
            dp[i] = max((dp[i-2] + nums[i]), dp[i-1]);
        }
        
        return dp[len - 1];
    }
};