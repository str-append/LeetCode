class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // vector<vector<int>>temp(n,vector<int>(m,-1));
        //transpose the matrix
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(matrix[j][i],matrix[i][j]);
            }
        }
        //reverse every row of matrix;
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         matrix[i][j] = temp[i][j];
        //     }
        // }
    }
};