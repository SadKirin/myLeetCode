/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

//用最高的柱子把数组分为两部分

class Solution {
public:
    int trap(vector<int>& height) {
        int max = 0;//最高柱子的下标
        
        for(int i = 0; i < height.size(); ++i){
            if(height[i] > height[max])
                max = i;
        }
        
        int water = 0;
        //先处理前一半
        for(int i = 0, peak = 0; i < max; ++i){
            if(height[i] > peak)
                peak = height[i];
            else
                water += peak - height[i];
        }
        //再处理后一半数组
        for(int i = height.size() - 1, top = 0; i > max; --i){
             if(height[i] > top)
                top = height[i];
            else
                water += top - height[i];
        }
        return water;
    }
};