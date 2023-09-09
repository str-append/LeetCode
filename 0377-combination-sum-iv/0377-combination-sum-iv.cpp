class Solution {
public:
    int f(vector<int>&nums,int t,vector<int>&dp){
        if(t==0) return 1;
        if(t<0) return 0;
        int ans=0;
        if(dp[t]!=-1) return dp[t];
        for(int i=0;i<nums.size();i++){
            ans+=f(nums,t-nums[i],dp);
        }
        return dp[t] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int>dp(target+5,0);
        dp[0] = 1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
            if(i-nums[j]>=0)
            dp[i]+=dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};