class Solution {
public:
    //memoisation
    int f(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return dp[i][j] = triangle[i][j];
        }
        if(dp[i][j]!=INT_MAX)
        return dp[i][j];
        int a=INT_MAX,b=INT_MAX;
        if(j>0)
        a=f(triangle,i-1,j-1,dp);
        if(j<triangle[i-1].size())
        b=f(triangle,i-1,j,dp);
        if(a==INT_MAX && b==INT_MAX)
        a=0,b=0;
        return dp[i][j] = min(a,b)+triangle[i][j];

    }
    int minimumTotal(vector<vector<int>>& triangle) {
       int m=0;
       for(auto i:triangle)
       m=max((int)i.size(),m);
       int ans=INT_MAX;
       vector<vector<int>>dp(triangle.size(),vector<int>(m,INT_MAX));
       for(int i=0;i<m;i++){
           ans = min(ans,f(triangle,triangle.size()-1,i,dp));
       }
       return ans;
    }
};