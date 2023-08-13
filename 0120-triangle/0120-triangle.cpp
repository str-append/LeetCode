class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=0;
        for(auto i:triangle){
            m=max((int)i.size(),m);
        }
        vector<vector<int>>dp(triangle.size(),vector<int>(m,INT_MAX));
        dp[0][0] = triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(i==0 && j==0){
                    dp[i][j]=triangle[0][0];
                }
                else{
                    int a=INT_MAX,b=INT_MAX;
                    if(j>0)
                    a=dp[i-1][j-1];
                    if(j<=triangle[i-1].size())
                    b=dp[i-1][j];
                    dp[i][j] = min(a,b)+triangle[i][j];
                }
            }
        }
        return *min_element(dp[triangle.size()-1].begin(),dp[triangle.size()-1].end());
    }
};