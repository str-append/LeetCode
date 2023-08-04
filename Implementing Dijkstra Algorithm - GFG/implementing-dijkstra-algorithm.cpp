//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        vector<int>dist(v,INT_MAX);
        dist[s]=0;
        set<pair<int,int>>st;
        st.insert({0,s});
        while(!st.empty()){
            auto itr = st.begin();
            auto pa = *itr;
            int di = pa.first;
            int node = pa.second;
            st.erase(itr);
            for(auto i:adj[node]){
                if(i[1]+di<dist[i[0]]){
                    dist[i[0]]=i[1]+di;
                    st.insert({dist[i[0]],i[0]});
                }
            }
        }
    
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends