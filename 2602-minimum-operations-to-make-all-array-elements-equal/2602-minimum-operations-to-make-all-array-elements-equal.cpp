class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        long long n = queries.size(), m = nums.size();
        sort(nums.begin(),nums.end());

        vector<long long>ps;
        long long sum =0;
        unordered_map<long long, int>last;
        for(int i=0;i<m;i++){
            last[nums[i]] = i;
            sum+=nums[i];
            ps.push_back(sum);

        }
        vector<long long>ans;
        for(auto &it:queries){
            int ind = lower_bound(nums.begin(),nums.end(),it) - nums.begin();
            long long left = 0;
            long long right = 0;
            long long lc=ind;
            long long rc=0;
            if(ind>0 && ind<m) {
                left = ps[ind-1];
                if(last.find(it)==last.end()){
                    right = sum - ps[ind-1];
                    rc = m - ind;
                }
                else{
                    right = sum - ps[last[it]];
                    rc = m -last[it]-1;
                }
                long long temp = (lc -rc)*it + right - left;
                ans.push_back(temp);
            }
            else if(ind==0){
                long long  temp = 0;
                if(nums[ind]==it)
                temp = sum - ps[last[it]] - (m-last[it]-1)*it;
                else temp = sum - m*it;
                ans.push_back(temp);

            }
            else{
                long long  temp = 0;
                temp = abs(sum - it*m);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};