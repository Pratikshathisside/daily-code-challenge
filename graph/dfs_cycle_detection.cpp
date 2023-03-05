#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<queue>
#include<list>

bool iscyclicbfs(int src, unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adjmatrix){
    unordered_map<int,int>parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto neighbour:adjmatrix[front]){
            if(visited[neighbour]==true && neighbour!=parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
q.push(neighbour);
visited[neighbour]=1;
parent[neighbour]= front;
            }
        }
    }
     return false;
}
bool iscyclicdfs(int node,int parent, unordered_map<int, bool> &visited,
                 unordered_map<int, list<int>> &adjmatrix) {
                     
                     visited[node] = true;

                     for(auto neighbour :adjmatrix[node]){
                         if(!visited[neighbour]){
                             bool cycledetected = iscyclicdfs(neighbour,node, visited, adjmatrix);
                             if (cycledetected) {
                               return true;
                             }
                         }
                         else if(neighbour!=parent){
                             return true;
                         }
                         
                         
                     }
return false;
                 }

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    //adjacent list
    unordered_map<int,list<int>> adjmatrix;
    for(int i =0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjmatrix[v].push_back(u);
        adjmatrix[u].push_back(v);
        
    }
    //handling disconnected components
    unordered_map<int,bool> visited;
    for(int i = 0 ;i<n; i++){
        if(!visited[i]){
            bool ans = iscyclicdfs(i,-1,visited,adjmatrix);
            if(ans ==1){
                return "Yes";
            }
        }
    }
    return "No";
}
