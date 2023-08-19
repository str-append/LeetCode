class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>deg(n,0);
        if(edges.size()==0)
            return {0};
        unordered_map<int,vector<int>>adj;
        vector<bool>vis(n,false);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans;
        queue<int>q;
        for(auto &it:adj){
            deg[it.first] = it.second.size();
            if(deg[it.first]==1) {
                q.push(it.first);
                vis[it.first] = true;
            }
        }
        while(!q.empty()){
            vector<int>temp;
            int n = q.size();
            for(int i=0;i<n;i++){
                int node = q.front();
                q.pop();
                temp.push_back(node);
                for(auto &it:adj[node]){
                    deg[it]--;
                    if(!vis[it] && deg[it]==1){
                        q.push(it);
                        vis[it] =true;
                    }
                }
            }
            ans = temp;
        }
        return ans;

    }
};