class Solution {
public:

    long long int recur(int ep, int k,int curr,vector<vector<long long int>>&dp){
        // cout<<curr<<" "<<k<<endl;
        if(curr==ep && k==0)
        return dp[curr][k]=1;
        else if(k<0)
        return 0;
        if(dp[curr][k]!=-1)
        return dp[curr][k];
        long long int a = recur(ep,k-1,curr-1,dp)+ recur(ep,k-1,curr+1,dp);
        return dp[curr][k]=a%((int)1e9+7);
    }
    int numberOfWays(int startPos, int endPos, int k) {
        if(startPos-k<0){
            endPos+=k+4;
            startPos+=k+4;
        }
        vector<vector<long long int>>dp(startPos+2*k+1,vector<long long int>(k+1,-1));    
            
        return recur(endPos,k,startPos,dp);
    }
};