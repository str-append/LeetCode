class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool>dp(nums.size()+1,false);
        dp[0] =true; //inital state
        dp[1] = false; // no good subsequence can be formed with only single element
        if(nums[0]==nums[1])
        dp[2]=true; // if first 2 elements are equal then only dp[2] can be true
        // curr state depends on only last 3 states
        for(int i=3;i<=nums.size();i++){
            //2 consecutive elements are equal
            if(nums[i-1]==nums[i-2] && dp[i-2]){ 
                dp[i]=true;
            }
            // 3 consecutive elements are equal;
            else if(nums[i-1]==nums[i-2] && nums[i-2]==nums[i-3] && dp[i-3])
            dp[i]=true;
            //incresing sequence with difference 1
            else if(nums[i-1]==nums[i-2]+1 && nums[i-2]==nums[i-3]+1 && dp[i-3])
            dp[i]=true;
        }
        return dp[nums.size()];
    }
};