class Solution {
public:
    int maxProfit(vector<int>& prices) {
        bool isBought = false;
        int n  = prices.size();
        int curr = 0;
        int pro = 0;
        if(prices.size()==1)
        return pro;
        for(int i=0;i<n;i++){
            if(isBought && ((i==n-1 && curr<prices[i]) || prices[i]>prices[i+1])){
                pro+=prices[i]-curr;
                isBought=false;
            }
            else if(!isBought && (i!=n-1 && (prices[i]<prices[i+1]))){
                isBought = true;
                curr = prices[i];
            }
        }
        return pro;
    }
        
};