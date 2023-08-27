class Solution {
public:
    //memoisation
    bool fun(vector<int>& stones, int ind, int prev,unordered_map<int,int>&mp,vector<vector<int>>&dp){
        if(ind>stones.size()-1 || prev<=0)
        return false;
        if(ind==stones.size()-1)
        return dp[ind][prev]=true;
        if(dp[ind][prev]!=-1){
            return dp[ind][prev];
        }
        bool kminus=false;
        bool k=false;
        bool kplus=false;
        if(mp.find(stones[ind]+prev)!=mp.end()){
            k = fun(stones,mp[stones[ind]+prev],prev,mp,dp);
        }
        if(prev>1 && mp.find(stones[ind]+prev-1)!=mp.end()){
            kminus = fun(stones,mp[stones[ind]+prev-1],prev-1,mp,dp);
        }
        if(mp.find(stones[ind]+prev+1)!=mp.end()){
            kplus = fun(stones,mp[stones[ind]+prev+1],prev+1,mp,dp);
        }

        return dp[ind][prev] = k | kminus | kplus;


    }
    //memoisation
    // bool canCross(vector<int>& stones) {
    //     unordered_map<int,int>mp;
    //     if(stones[1]!=1)
    //     return false;
    //     int n = stones.size();
    //     vector<vector<int>>dp(n+1,vector<int>(n+500,-1));
    //     for(int i=0;i<stones.size();i++){
    //         mp[stones[i]]=i;
    //     }
    //     return fun(stones,1,1,mp,dp);
    //     return false;
    // }

    //tabulation
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)
        return false;

        int n = stones.size();

        unordered_map<int,int>mp;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        
        vector<vector<int>>dp(n+1,vector<int>(n+5,0));

        dp[0][0]=1;

        for(int i=0;i<n;i++){
            for(int jump=0;jump<=n;jump++){
                if(dp[i][jump]){
                    if(mp.find(stones[i]+jump) !=mp.end()){
                        int indexafterjump = mp[stones[i]+jump];
                        dp[indexafterjump][jump] = 1;
                    }
                    if(mp.find(stones[i]+jump+1)!=mp.end()){
                        int indexafterjump = mp[stones[i]+jump+1];
                        dp[indexafterjump][jump+1] = 1;
                    }
                    if(jump>0 && mp.find(stones[i]+jump-1) !=mp.end()){
                        int indexafterjump = mp[stones[i]+jump-1];
                        dp[indexafterjump][jump-1] = 1;
                    }
                    if(i==n-1 && dp[n-1][jump]==1)
                    return true;
                }
            }
        }
        return false;
    }
};