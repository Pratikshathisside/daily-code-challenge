#include <bits/stdc++.h> 
#include<stack>
#include<unordered_map>
#include<list>
#include<queue>
// void toposort(int node , vector<bool>&visited,stack<int>&st,unordered_map<int,list<int>>&adj){
//     visited[node]= 1;
//     for(auto neighbour: adj[node]){
//         if(!visited[neighbour])
// toposort(neighbour, visited, st, adj);
//     }
//     st.push(node);
// }
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int, list<int>> adj;
    for(int i = 0; i<e ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        //though given ggraph is directed one
    
    }
    //finding all indegrees
    vector<int> indegree(v);
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

//0 indegree jinpe hai unko push krvao
queue<int> q;
for(int i = 0; i<v;i++){
    if(indegree[i]==0){
        q.push(i);

    }
}
//do bfs
vector<int> ans;
while(!q.empty()){
    int front = q.front();
    q.pop();
    ans.push_back(front);
    for(int neighbour:adj[front]){
        indegree[neighbour]--;
if(indegree[neighbour]==0){
    q.push(neighbour);
}
    }
}
    return ans;

}
