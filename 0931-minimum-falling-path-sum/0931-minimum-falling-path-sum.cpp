class Solution {
public:
    //tabulation
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int a=INT_MAX;
                int b=INT_MAX;
                int c=INT_MAX;

                if(j>0){
                    a=dp[i-1][j-1];
                }
                if(j+1<m)
                b=dp[i-1][j+1];
                c=dp[i-1][j];
                dp[i][j] = min({a,b,c})+matrix[i][j];
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};