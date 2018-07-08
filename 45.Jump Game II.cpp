/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0;
        int bound = 0;
        int step = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if(i > maxReach){
                return 0;
            }
            
            if(i > bound){
                ++step;
                bound = maxReach;
            }
            maxReach = max(maxReach, i+nums[i]);
        }
        return step;
    }
};