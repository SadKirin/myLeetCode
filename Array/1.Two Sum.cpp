/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
//数组无序
class Solution {
public:
    //O(n2)解法
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> res;
      int length = nums.size();
      if(length < 2)
          return res;
        
      int i,j = 0;
      bool flag = false;
      for(i = 0; i< length; ++i){
          for(j = i+1; j < length; ++j){
              if(nums[i] + nums[j] == target){
                  flag = true;
                  break;
              }
          }
          if(flag)
              break;
      }
      res.push_back(i);
      res.push_back(j);
      return res;
    }

    //利用unordered_map  进行哈希映射
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> res;
      if(nums.size() <= 1){
          return res;
      }
        
      unordered_map<int,int> map;
      for(int i = 0; i < nums.size(); ++i){
          map[nums[i]] = i;//key是数组的数字，value是数字的下标
      }  
      
      for(int i = 0; i < nums.size(); ++i){
          int other = target - nums[i];
          if(map.find(other) != map.end() && map[other] > i){
              res.push_back(i);
              res.push_back(map[other]);
              return res;
              break;
          }
      }
      // 无解的情况
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
};