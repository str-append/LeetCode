class Solution {
public:
    int recur(int amount,vector<int>&coins,int ind,vector<vector<int>>&dp){
        // cout<<ind<<" "<<amount<<endl;
        // if(ind>=coins.size() || amount<0)
        // return 0;
        if(amount==0){
            return 1;
        }
        if(ind==0)
        {
            // cout<<ind<<" "<<amount<<endl;
            if(amount%coins[0]==0)
            return  dp[ind][amount] = 1;
            return  dp[ind][amount] = 0;
        }
        if(dp[ind][amount]!=-1)
        return dp[ind][amount];
        int a = 0;
        int b = 0;
        if(amount-coins[ind]>=0)
        a = recur(amount-coins[ind],coins,ind,dp);
        if(ind>0)
        b = recur(amount,coins,ind-1,dp);
        return dp[ind][amount] = a+b;
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return recur(amount,coins,coins.size()-1,dp);
    }
};