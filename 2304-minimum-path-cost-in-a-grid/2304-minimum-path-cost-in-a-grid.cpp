class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>curr(m,0);
        for(int i=1;i<n;i++){ //coming to ith row
            vector<int>temp(m,0);
            //going to the other columns of ith row from 0th column of i-1th row
            for(int j=0;j<m;j++){
                if(i==1){
                    int val = curr[0]+grid[i-1][0]+grid[i][j]+moveCost[grid[i-1][0]][j];
                    temp[j] = val;
                }
                else {
                    //grid[i-1][0] is already calculated in curr
                    int val = curr[0]+grid[i][j]+moveCost[grid[i-1][0]][j];
                    temp[j] = val;
                }
                
            }
            //for 1st column onwards
            for(int k=1;k<m;k++){
                for(int j=0;j<m;j++){
                    if(i==1){
                         int val = curr[k]+grid[i-1][k]+grid[i][j]+moveCost[grid[i-1][k]][j];
                    temp[j]=min(temp[j],val);
                    }
                    else{
                        int val = curr[k]+grid[i][j]+moveCost[grid[i-1][k]][j];
                        temp[j]=min(temp[j],val);
                    }
                   
                }
            }
            curr = temp;
        }   
        return *min_element(curr.begin(),curr.end());
    }
};