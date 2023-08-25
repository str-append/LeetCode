class Solution {
public:
    bool fun(string s1, string s2, string s3,int ind,int p, int q,vector<vector<int>>&dp){
        if(ind==s3.size() && p==s1.size() && q==s2.size() )
        return  dp[q][p] = true;
        if(p==s1.size() && q==s2.size()){
            return  dp[q][p]= false;
        }
        if(ind==s3.size())
        return  dp[q][p]=false;
        if(dp[q][p]!=-1)
        return dp[q][p];
        bool take1 = false;
        bool take2 = false;
        if(p<s1.size() && s1[p]==s3[ind]){
            take1 = fun(s1,s2,s3,ind+1,p+1,q,dp);
        }
        if(q<s2.size() && s2[q]==s3[ind]){
            take2 = fun(s1,s2,s3,ind+1,p,q+1,dp);
        }
        return dp[q][p] = take1 | take2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>>dp(s2.size()+1,vector<int>(s1.size()+1,-1));
        return fun(s1,s2,s3,0,0,0,dp);
    }
};