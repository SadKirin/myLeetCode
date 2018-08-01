/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitSum[32] = {0};//一个int4字节，一个字节8bit，一个int型数组需要32bit表示
        for(int i = 0; i < nums.size(); ++i){
            int bitMask = 1;
            for(int j = 31; j >= 0; --j){  //从最低位开始
                int bit = nums[i] & bitMask;
                if(bit != 0){
                    bitSum[j] += 1; //该位上所有数字二进制的和
                }
                bitMask = bitMask << 1;
            }
        }
        int res = 0;
        for(int i = 0; i < 32; ++i){//从最高位开始
            res = res << 1;
            res += bitSum[i] % 3; //如果能被3整除，该位为0；否则说明该位上出现了 只出现一次的数字
        }
        return res;
    }
};