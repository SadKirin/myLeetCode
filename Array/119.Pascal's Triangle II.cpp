/*
输出杨辉三角的第n行
*/

//考虑到可能会被覆盖，所以需要从后向前进行迭代计算

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        
        res.resize(rowIndex + 1, 1);// row index starts from 0.
        for(int i = 0; i < rowIndex + 1; ++i){
            for(int j = i - 1; j >= 1; --j){
                res[j] = res[j] + res[j-1];
            }
        }
        return res;
    }
};