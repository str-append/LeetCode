class Solution {
public:
    bool f(vector<int>& nums, int ind,int cs, int target,vector<vector<int>>&dp){
        if(cs==target){
            return true;
        }
        if(cs>target || (ind==nums.size() && cs!=target))
        return false;
        if(dp[ind][cs]!=-1)
        return dp[ind][cs];
        bool take=false, notTake=false;
        take = f(nums,ind+1,cs+nums[ind],target,dp);
        notTake = f(nums,ind+1,cs,target,dp);
        return dp[ind][cs] = take|notTake;
    }
    bool canPartition(vector<int>& nums) {
        long long int sum = 0;
        sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1)
        return false;
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum,-1));
        sum=sum/2;
        return f(nums,0,0,sum,dp);
    }   
};