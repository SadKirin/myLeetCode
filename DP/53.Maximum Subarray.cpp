/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        
        vector<int> dp(length);
        dp[0] = nums[0];
        int Max = dp[0];
        
        for(int i = 1; i < length; ++i){
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            Max = max(dp[i],Max);
        }
        
        return Max;
    }
};