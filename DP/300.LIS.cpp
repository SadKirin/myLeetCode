class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len <= 0)
            return 0;
        //dp[i]代表在i位置的最大上升子序列长度
        //dp[i]最小为1.由自身一个数字构成
        vector<int> dp(len,1);
        
        int result = 1;
        dp[0] = 1;
        for(int i = 1; i < len; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            //前i-1个元素中可能有多个LIS，取其中的最大
            result = max(result, dp[i]);
        }
        
        return result;
    }
};