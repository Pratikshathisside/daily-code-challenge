#include <bits/stdc++.h> 
#include<stack>
#include<unordered_map>
#include<list>
void toposort(int node , unordered_map<int,bool>&visited,stack<int>&st,unordered_map<int,list<int>>&adj){
    visited[node]= 1;
    for(auto neighbour: adj[node]){
        if(!visited[neighbour])
toposort(neighbour, visited, st, adj);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int, list<int>> adj;
    for(int i = 0; i<e ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        //though given ggraph is directed one
    
    }
    unordered_map<int,bool> visited;
    stack<int>st;
    for(int i = 0; i<v; i++){
      if (!visited[i]) {
        toposort(i, visited, st, adj);
      }
}
    
    

vector<int> ans;
while(!st.empty()){
    ans.push_back(st.top());
st.pop();
}

    return ans;

}



//betttttttter optimization
#include <bits/stdc++.h> 
#include<stack>
#include<unordered_map>
#include<list>
void toposort(int node , vector<bool>&visited,stack<int>&st,unordered_map<int,list<int>>&adj){
    visited[node]= 1;
    for(auto neighbour: adj[node]){
        if(!visited[neighbour])
toposort(neighbour, visited, st, adj);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int, list<int>> adj;
    for(int i = 0; i<e ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        //though given ggraph is directed one
    
    }
    vector<bool> visited(v);
    stack<int>st;
    for(int i = 0; i<v; i++){
      if (!visited[i]) {
        toposort(i, visited, st, adj);
      }
}

vector<int> ans;
while(!st.empty()){
    ans.push_back(st.top());
st.pop();
}

    return ans;

}
