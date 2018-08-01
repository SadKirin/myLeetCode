/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
*/
//设置标志位，将数组分成两部分，这两部分中各含一个单独出现的数字
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int _xor = 0;
        for(int i = 0; i < nums.size(); ++i){
            _xor ^= nums[i];
        }
        
        _xor &= ~(_xor - 1); //get the last set bit  获取最后一个标志位
        vector<int> res(2,0);
        
        for (int num : nums)
        {
            if ((num & _xor) == 0) // the bit is not set 把数组分成两部分，这两部分中各含一个单独出现的数字
            {
                res[0] ^= num;
            }
            else // the bit is set
            {
                res[1] ^= num;
            }
        }
        return res;
    }
};