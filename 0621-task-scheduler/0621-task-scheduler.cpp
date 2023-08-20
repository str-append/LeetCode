class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>map;
        for(auto it:tasks)
        map[it]++;
        priority_queue<pair<int,char>>pq;
        for(auto it:map){
            pq.push({it.second,it.first});
        }
        queue<pair<int,char>>q;
        int t = 0;
        while(!pq.empty() || !q.empty()){
            if(!pq.empty()){
                auto p = pq.top();
                pq.pop();
                map[p.second]--;
                if(map[p.second]>0){
                    q.push({t+n,p.second});
                }
            }
            if(!q.empty() && q.front().first<=t){
                auto p = q.front();
                q.pop();
                pq.push({map[p.second],p.second});
            }
            t++;
        }
        return t;
    }
};