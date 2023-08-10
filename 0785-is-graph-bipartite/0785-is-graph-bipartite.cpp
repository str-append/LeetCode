class Solution {
public:
    bool bfs(unordered_map<int,vector<int>>&gh,vector<int>&col,int ind){
        queue<int>q;
        q.push(ind);
        col[ind] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int nc = col[node];
            for(auto i:gh[node]){
                if(col[i]==-1){
                    col[i] = !nc;
                    q.push(i);
                }
                else if(col[i]==nc)
                return false;
            }
        } 
        return true;

    }
    bool dfs(unordered_map<int,vector<int>>&gh,vector<int>&col,int ind){
        for(auto i:gh[ind]){
            if(col[i]==-1){
                col[i] = !col[ind];
                if(!dfs(gh,col,i))
                return false;
            }
            else if(col[i]==col[ind])
            return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>gh;
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()>0)
            for(auto j:graph[i]){
                gh[i].push_back(j);
                gh[j].push_back(i);
            }
        }
        vector<int>col(graph.size(),-1);
        for(auto i:gh){
            if(col[i.first]==-1){
                if(!dfs(gh,col,i.first))
                return false;
            }
        }
        return true;
    }
};