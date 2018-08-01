/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
*/
//sum 判断当前指针位置的有效性
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;//整个数组是否有解
        int j = -1;
        for(int i = 0, sum = 0; i < gas.size(); ++i){
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if(sum < 0){//不能成为出发点，油不够
                j = i;//保存最后一个不能成为出发点的位置
                sum = 0;//sum归零
            }
        }
        
        return (total >= 0) ? (j + 1) : -1;
    }
};