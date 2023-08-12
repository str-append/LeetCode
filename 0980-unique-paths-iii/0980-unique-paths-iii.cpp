class Solution {
public:
    vector<vector<int>>dir ={{-1,0},{1,0},{0,-1},{0,1}};
    int f(vector<vector<int>>&grid,int row,int col,int count){
        if(grid[row][col]==2){ //destination
            if(count==grid.size()*grid[0].size()) //all visitable position visited
            {
                return 1;
            }
            return 0;
        }
        int a = grid[row][col]; //storing the initial value of a visited positon;
        grid[row][col]=-1; //marking it as visited;
        int ans=0;
        for(int i=0;i<dir.size();i++){
            int r = row + dir[i][0];
            int c = col + dir[i][1];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]!=-1 ){
                ans+=f(grid,r,c,count+1);
            }
        }
        grid[row][col] = a; //restoring the initial value of grid
        return ans;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr=0,sc=0; //starting row, starting column 
        int c=0; //adding all the starting index and all obstacle as initial count
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                    c++;
                }
                else if(grid[i][j]==-1){
                    c++;
                }
            }
        }
        int recur= f(grid,sr,sc,c);
        return recur;
    }
};