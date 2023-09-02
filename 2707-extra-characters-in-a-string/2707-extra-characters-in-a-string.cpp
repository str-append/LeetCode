class Solution {
public:
    int f(string s,unordered_set<string>&st,int ind,vector<int>&dp)
    {
        if(ind>s.size()-1)
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int take=1e8,nt=1e8;
        nt = 1+f(s,st,ind+1,dp);
        for(int i=ind;i<s.size();i++){
            if(st.find(s.substr(ind,i-ind+1))!=st.end()){
                take = min(take,f(s,st,i+1,dp));
            }
        }
        return dp[ind] = min(take,nt);

    }
    // int minExtraChar(string s, vector<string>& dict) {
    //     unordered_set<string>st(dict.begin(),dict.end());
    //     vector<int>dp(s.size()+1,-1);
    //     return f(s,st,0,dp);
    // }

    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string>st(dict.begin(),dict.end());
        vector<int>dp(s.size()+1,0);
        int n = s.size();
        for(int i=1;i<=n;i++){
            int nottake = 1+dp[i-1];
            int take =1e8;
            for(int j=0;j<i;j++){
                if(st.find(s.substr(j,i-j))!=st.end()){
                    take = min(take,dp[j]);
                }
            }
            dp[i] = min(take,nottake);
        }
        return dp[n];
    }
};