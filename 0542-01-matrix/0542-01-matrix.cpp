class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //dp solution
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) continue;
                int top=1e8, left = 1e8;
                if(i>0) top = mat[i-1][j];
                if(j>0) left = mat[i][j-1];
                mat[i][j] = min(top,left)+1;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]==0) continue;
                int bottom=1e8, right = 1e8;
                if(i<n-1) bottom = mat[i+1][j];
                if(j<m-1) right = mat[i][j+1];
                mat[i][j] = min(mat[i][j],(min(bottom,right)+1));
            }
        }
        return mat;
    }
};