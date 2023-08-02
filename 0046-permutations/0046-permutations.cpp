class Solution {
public:
    void recur(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        // cout<<ind<<endl;
        if(temp.size()==nums.size()){
            // temp.push_back(nums[ind]);
            ans.push_back(temp);
            return;
        }
        for(auto i:nums){
            if(find(temp.begin(),temp.end(),i)==temp.end()){
                temp.push_back(i);
                recur(nums,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        recur(nums,temp,ans);
        return ans;

        

    }
};