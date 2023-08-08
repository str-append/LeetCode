class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro=0;
        int mp = INT_MAX;
        for(auto i:prices){
            mp = min(i,mp);
            pro = max(pro,i-mp);
        }
        return pro;
    }
};