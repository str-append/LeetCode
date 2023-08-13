class Solution {
public:
    bool validPartition(vector<int>& nums) {
        //space optimisation
        bool a=true,b=false,c=false,curr=false;
        if(nums[0]==nums[1])
        c=true;
        for(int i=3;i<=nums.size();i++){
            curr=false;
            //2 consecutive elements are equal
            if(nums[i-1]==nums[i-2] && b)
                curr=true;

            // 3 consecutive elements are equal;
            else if(nums[i-1]==nums[i-2] && nums[i-2]==nums[i-3] && a)
                curr=true;

            //incresing sequence with difference 1
            else if(i>=3 && nums[i-1]==nums[i-2]+1 && nums[i-2]==nums[i-3]+1 && a)
                curr=true;

            a=b;
            b=c;
            c=curr;
        }
        return c;
    }
};