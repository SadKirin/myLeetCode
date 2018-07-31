/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.
*/

//sum为计数器，记录重复元素出现的次数。当重复次数大于等于2时，直接跳过。

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int j = 0;
        int sum = 0;
        for(int i=1;i<nums.size();++i){
            if(nums[j] == nums[i]){
                sum++;
                if(sum < 2){
                  nums[++j] = nums[i];
                }
            }
            else{
                nums[++j] = nums[i];
                sum = 0;
            }
        }
        return j+1;
    }
};