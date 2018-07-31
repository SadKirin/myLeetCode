/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

//可以推广到k-sum   先对数组进行排序，然后做k-2层循环，最内层循环中再使用two pointers进行夹逼。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.size() < 3){
            return res;
        }
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < nums.size() - 2; ++i){//先做k-2层循环，这里K等于3,，所以只需要做一次循环
            int j = i + 1;
            int k = nums.size()-1;
            while(j < k){//最内层循环里两头夹逼
                vector<int> tmp;
                if(nums[i]+nums[k]+nums[j] == 0){
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    res.push_back(tmp);
                    ++j;
                    --k;
                    
                    while(j < k && nums[j-1] == nums[j]) //去除重复
                        ++j;
                    while(j < k && nums[k] == nums[k+1]) //去除重复
                        --k;
                }
                else if(nums[i]+nums[k]+nums[j] < 0)
                    ++j;
                     else
                        --k; 
            }
            while(i < nums.size() - 2 && nums[i] == nums[i+1]) //去除重复
                ++i;
        }
        return res;
    }
};