/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        bool row_has_zero = false;
        bool col_has_zero = false;
        
        //因为要复用第一行和第一列，所以先保存下来第一行第一列的信息
        for(int i = 0; i < row; i++){
            if(matrix[0][i] == 0){
                row_has_zero = true;
                break;
            }
        }
        for(int i = 0; i < col; i++){
            if(matrix[i][0] == 0){
                col_has_zero = true;
                break;
            }
        }
        
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }        
            }
        }
        
        if(row_has_zero){
            for(int i = 0; i < row; i++){
                matrix[0][i] = 0;
            }
        }
        if(col_has_zero){
            for(int i = 0; i < col; i++){
                matrix[i][0] = 0;
            }
        }
    }
};