#include<unordered_map>
#include<list>
void dfs(int node,int parent,unordered_map<int,list<int>>&adj,
unordered_map<int,bool>&visited,vector<int>&disc,vector<int>&low,int timer,
vector<vector<int>>&bridges){
    visited[node]=1;
    disc[node]=low[node]=timer++;
    for(auto nbr : adj[node]){
        //neighbour is parent
        if(nbr==parent){
            continue;
        }
        //a neighour which is not visited and not the parent
        else if(!visited[nbr]){
            dfs(nbr,node,adj, visited, disc, low, timer, bridges);
            low[node]=min(low[node],low[nbr]);
            //main condition to check if the edge is a bridge
            if(low[nbr]>disc[node]){
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(nbr);
                bridges.push_back(ans);

            }

        }
        ////check if back edge or not
        else{
            low[node]=min(low[node],low[nbr]);
        }
    }


}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int,list<int>>adj;
    unordered_map<int,bool>visited;
    vector<int>disc(v);
    vector<int>low(v);
    int timer=0;

    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>bridges;
    int parent=-1;
    for(int i=0;i<v;i++){
        if(!visited[i]){
      dfs(i, parent, adj, visited, disc, low, timer, bridges);
        }
    }
    return bridges;
}
