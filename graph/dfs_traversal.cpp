void dfs(int node,vector<int>&component, unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adjlist ){
    component.push_back(node);
    visited[node]=1;
    for(auto i: adjlist[node]){
        if(!visited[i]){
            dfs(i, component, visited, adjlist);
        }

    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,list<int>> adjlist;
    for(int i = 0; i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    //now creating a 2d array to store ans
    vector<vector<int>> ans;
    unordered_map<int,bool>visited;

    //checking for all
    for(int i = 0; i<V;i++){
        if(!visited[i]){
            vector<int>component;
            dfs(i,component,visited,adjlist);
            ans.push_back(component);
        }
    }
    return ans;

}
