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
    int tempmemoisation(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1)
        return 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return recur(obstacleGrid,0,0,dp);
    }

    //tabulation
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1 ||obstacleGrid[0][0]==1 )
        return 0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                // cout<<"row "<<row<<" "<<col<<endl;
                if(row==0 && col==0){
                    dp[row][col] =1;
                }
                else if(obstacleGrid[row][col]==1)
                dp[row][col]= 0;
                else{
                    dp[row][col] =0;
                    if(row>0)
                    dp[row][col]+=dp[row-1][col];
                    if(col>0){
                        dp[row][col]+=dp[row][col-1];
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};