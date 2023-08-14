class Solution {
public:
    //use &t otherwise TLE
    int fun(string &t1,string &t2, int i, int j,vector<vector<int>>&dp){
        if(i<0 || j<0)
        return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(t1[i]==t2[j]){
            return dp[i][j] =  1+fun(t1,t2,i-1,j-1,dp);
        }
        else return dp[i][j] = max(fun(t1,t2,i-1,j,dp),fun(t1,t2,i,j-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(text1,text2,text1.size()-1,text2.size()-1,dp);   
    }
};