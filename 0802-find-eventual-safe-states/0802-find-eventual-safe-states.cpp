class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>map;
        vector<int>indeg(graph.size(),0);
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            indeg[i] = graph[i].size();
            if(indeg[i]==0)
            q.push(i);
            for(int j=0;j<graph[i].size();j++){
                map[graph[i][j]].push_back(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int safe = q.front();
            ans.push_back(safe);
            q.pop();
            for(auto i:map[safe]){
                indeg[i]--;
                if(indeg[i]==0)
                q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};