/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int length = cost.size();
        //dp[i]表示到达第i层阶梯所需要的最小cost
        vector<int> dp(length);
        //初始化dp矩阵
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i = 2; i < length; ++i){
            dp[i] = min(dp[i - 1],dp[i - 2]) + cost[i];
        }
        
        //返回dp[length - 1]和dp[length - 2]中的最小值，因为到达top有两种方法。
        return min(dp[length - 1],dp[length - 2]);
    }
};