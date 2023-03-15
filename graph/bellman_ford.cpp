#include <bits/stdc++.h> 
#include<unordered_map>
#include<vector>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code he> adj;re.
    vector<int>dist(n+1,1e9);
    dist[src]=0;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(dist[u]!=1e9 && (dist[u]+wt<dist[v])){
                dist[v] = dist[u]+wt;
            }
        }
    }
    //check for negative cycles
    bool flag = 0;
    for(int i = 0; i<m ; i++){
       int u = edges[i][0];
       int v = edges[i][1];
       int wt = edges[i][2];
       if((dist[u]+wt<dist[v])&& dist[u]!=1e9){
           flag = 1;
       }
    }
    if(flag ==0){
        return dist[dest];
    }
    return -1;
}
