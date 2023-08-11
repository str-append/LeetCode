class Solution {
public:
    int recur(int amount,vector<int>&coins,int ind,vector<vector<int>>&dp){
        if(ind==0){
            return amount%coins[0]==0?1:0;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int notTake = recur(amount,coins,ind-1,dp);
        int take=0;
        if(coins[ind]<=amount){
            take = recur(amount-coins[ind],coins,ind,dp);
        }
        return dp[ind][amount] =  take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return recur(amount,coins,coins.size()-1,dp);
    }
};