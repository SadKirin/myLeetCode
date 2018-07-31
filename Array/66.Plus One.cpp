/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/

//精确加法。c为进位

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        add(digits,1);
        return digits;
    }
private:
    void add(vector<int>& digits, int digit){
        int c = digit;
        
        for(auto it = digits.rbegin(); it != digits.rend(); ++it){
            *it += c; 
            c = *it / 10; //c为产生的进位
            *it %= 10; //进位后该位的数值
        }
        
        if(c > 0){
            digits.insert(digits.begin(),1);
        }
    }
    
};