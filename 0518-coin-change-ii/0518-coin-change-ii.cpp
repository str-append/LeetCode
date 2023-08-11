class Solution {
public:
    
    //memoisation
    // int recur(int amount,vector<int>&coins,int ind,vector<vector<int>>&dp){
    //     if(ind==0){
    //         return amount%coins[0]==0?1:0;
    //     }
    //     if(dp[ind][amount]!=-1){
    //         return dp[ind][amount];
    //     }
    //     int notTake = recur(amount,coins,ind-1,dp);
    //     int take=0;
    //     if(coins[ind]<=amount){
    //         take = recur(amount-coins[ind],coins,ind,dp);
    //     }
    //     return dp[ind][amount] =  take+notTake;
    // }
    
    
    //tabulaiton
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            dp[0][i]=i%coins[0]==0?1:0;
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                int notTake = dp[i-1][j];
                int Take =0;
                if(coins[i]<=j)
                Take = dp[i][j-coins[i]];
                dp[i][j]=notTake+Take;
            }
        }
        return dp[coins.size()-1][amount];
    }
};