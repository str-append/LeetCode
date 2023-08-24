class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int> &a, vector<int> &b)->bool {
            return a[1]<b[1]; //equal sign (<=) gives the error
            /*
             runtime error: applying non-zero offset 4 to null pointer (stl_vector.h)
            */
        });
        
        int i=0;
        long long ans=0;
        while(i<points.size()){
            int x = points[i][1];
            // cout<<x<<endl;
            ans++;
            int j=i;
            while(j<points.size()) {
                // cout<<" j "<<points[j][0]<<endl;
                if(points[j][1]>=x && points[j][0]<=x)
                j++;
                else{
                    break;
                }
            }
            if(i==j){
                i++;
            }
            else
            i=j;
        }

        return ans;


    }
};