class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>dir = {{-1,0},{1,0},{0,1},{0,-1}};
        queue<vector<int>>q;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    mat[i][j]=-1;
                }
            }
        }
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int row = temp[0];
            int col = temp[1];
            int dist = temp[2];
            for(int i=0;i<4;i++){
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                if(r<n && r>=0 && c<m && c>=0 && mat[r][c]!=-1){
                    ans[r][c] = dist+1;
                    q.push({r,c,dist+1});
                    mat[r][c]=-1;
                }
            }
        }
        return ans;
    }
};