class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0){
            return 0;
        }
        int row = triangle.size();
        
        //dp[i][j]表示在 从第(i,j)位置开始到最低端的最小路径和 
        //dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
        //优化使用一位数组：
        //dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);
        vector<int> dp(row);
        
        for(int i = 0; i < triangle[row - 1].size(); ++i){
            dp[i] = triangle[row - 1][i];
        }
        
        //从倒数第二行开始
        for(int i = row - 2; i >=0; --i){
            for(int j = 0; j <= i; ++j){
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        
        return dp[0];
    }
};