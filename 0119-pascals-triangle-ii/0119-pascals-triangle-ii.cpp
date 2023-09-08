class Solution {
public:
    vector<int> getRow(int r) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(r==0)
        return ans[r];
        ans.push_back({1,1});
        if(r==1)
        return ans[r];
        for(int i=2;i<=r;i++){
            vector<int>temp(i+1,1);
            for(int j=1;j<i;j++){
                temp[j] = ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(temp);
        }
        return ans[r];
    }
};