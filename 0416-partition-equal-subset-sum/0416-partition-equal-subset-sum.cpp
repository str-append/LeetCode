class Solution {
public:
    bool memoisation(vector<int>& nums, int ind,int cs, int target,vector<vector<int>>&dp){
        if(cs==target){
            return true;
        }
        if(cs>target || (ind==nums.size() && cs!=target))
        return false;
        if(dp[ind][cs]!=-1)
        return dp[ind][cs];
        bool take=false, notTake=false;
        take = memoisation(nums,ind+1,cs+nums[ind],target,dp);
        notTake = memoisation(nums,ind+1,cs,target,dp);
        return dp[ind][cs] = take|notTake;
    }
    bool canPartition(vector<int>& nums) {
        //tabulation
        long long int sum = 0;
        sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1)
        return false;
        vector<vector<bool>>dp(nums.size()+1,vector<bool>(sum+1,false));
        sum=sum/2;
        for(int i=0;i<nums.size();i++){
            dp[i][0]=true;
        }
        dp[0][nums[0]] = true;
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=sum;j++){
                bool take=false, notTake=false;
                if(j-nums[i]>=0)
                take = dp[i-1][j-nums[i]];
                notTake=dp[i-1][j];
                dp[i][j] = take|notTake;
            }
        }
        return dp[nums.size()-1][sum];
    }   
};