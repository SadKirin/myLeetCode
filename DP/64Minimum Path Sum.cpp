class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(row == 0 || col == 0){
            return 0;
        }
        
        vector<vector<int>> dp(row, vector<int>(col));
        //dp[i][j]表示当前在(i,j)点处的最小路径和 
        dp[0][0] = grid[0][0];
        
        //初始化第一行和第一列
        for(int i = 1; i <row; ++i){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        
        for(int i = 1; i <col; ++i){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[row-1][col-1];
    }
};