class Solution {
public:

//tabulation of LCS
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+2,vector<int>(m+2,0));
        for(int i=0;i<=m;i++){
            dp[0][i] = 0;
        }

        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }

        // cout<<n<<" "<<m<<endl; 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){ 
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    // cout<<i<<" "<<j<<endl; 
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int ans = dp[n][m];
        // cout<<ans<<endl; 

        return abs(n-ans)+abs(m-ans); 

    }
};