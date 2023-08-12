class Solution {
public:
    //memoisation
    int recur(vector<vector<int>>&og,int row,int col,vector<vector<int>>&dp){
        if(row==og.size()-1 && col ==og[0].size()-1){
            return 1;
        }
        if(row>og.size()-1 || col>og[0].size()-1 || og[row][col]==1)
        return 0;
        if(dp[row][col]!=-1)
        return dp[row][col];
        int a = recur(og,row,col+1,dp)+recur(og,row+1,col,dp);
        return dp[row][col] = a;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1)
        return 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return recur(obstacleGrid,0,0,dp);
    }
};