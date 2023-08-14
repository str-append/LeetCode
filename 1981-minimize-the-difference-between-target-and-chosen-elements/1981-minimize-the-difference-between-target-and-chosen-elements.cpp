class Solution {
public:
    int f(vector<vector<int>>&mat, int target, int r,long long int cs,vector<vector<long long int>>&dp){
        if(r<0){
            return abs(cs-target);
        }

        if(dp[r][cs]!=-1)
        return dp[r][cs];

        int mi = INT_MAX;
        for(int i=0;i<mat[0].size();i++){
            mi = min(mi,f(mat,target,r-1,cs+mat[r][i],dp));
        }
        
        return dp[r][cs] = mi;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        vector<vector<long long int>>dp(mat.size()+1,vector<long long int>(50001,-1));
        return f(mat,target,mat.size()-1,0,dp);
    }   
};