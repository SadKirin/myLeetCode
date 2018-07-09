/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
*/
class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            data.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0){
            return data[j];
        }
        else
            return data[j] - data[i - 1];
    }
private:
    vector<int> data;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */