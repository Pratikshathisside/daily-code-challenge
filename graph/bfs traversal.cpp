#include <bits/stdc++.h> 
void prepareadj(unordered_map<int, set<int>> &adjlist,vector<pair<int, int>> edges){
    for(int i = 0; i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }
}
void bfs(unordered_map<int, set<int>> &adjlist,unordered_map<int,bool> &visited,vector<int> &ans,int node){
       queue<int>q;
       q.push(node);
       visited[node]=1;
       while(!q.empty()){
           int frontnode = q.front();
           q.pop();
           //storing front node in the ans
           ans.push_back(frontnode);
           //traversing all neighbours
           for(auto i: adjlist[frontnode]){
               if(!visited[i]){
                   q.push(i);
                   visited[i]=1;
               }

           }
       }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int, set<int>> adjlist;
    vector<int> ans;
    unordered_map<int,bool> visited;

    //now prepare a adjacent list
    prepareadj(adjlist,edges);
    //now travesing evry elementt
    for(int i = 0 ; i<vertex; i++){
        if(!visited[i]){
            bfs(adjlist,visited,ans,i);

        }
    }
return ans;

}
