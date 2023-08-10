class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>graph;
        for(auto i:times){
            graph[i[0]-1].push_back({i[1]-1,i[2]});
        }
        vector<int>dist(n,INT_MAX);
        dist[k-1]=0;
        set<pair<int,int>>s;
        s.insert({0,k-1});
        while(!s.empty()){
            auto itr= s.begin();
            auto p =*itr;
            s.erase(itr);
            int node = p.second;
            int dis = p.first;
            for(auto i:graph[node]){
                if(dis+i.second<dist[i.first])
                {
                    dist[i.first] = dis+i.second;
                    s.insert({dist[i.first],i.first});
                }
            }
        }
        return *max_element(dist.begin(),dist.end())==INT_MAX?-1:*max_element(dist.begin(),dist.end());
    }
};