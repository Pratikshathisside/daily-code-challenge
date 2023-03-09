#include <bits/stdc++.h> 
#include<unordered_map>
#include<set>
#include<list>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i = 0; i<edges;i++){
        int u = vec[i][0];
        int v  = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int>dist(vertices);
    for(int i  = 0; i<vertices;i++){
        dist[i]= INT_MAX;
    }
    set<pair<int,int>>st;
    dist[source]=0;
st.insert(make_pair(0,source));
while(!st.empty()){
    auto top =*(st.begin());
    int nodedistance = top.first;
    int nodeval = top.second;
    st.erase(st.begin());
    //traverse on neighbour
    for(auto neighbour:adj[nodeval]){
if(nodedistance + neighbour.second<dist[neighbour.first]){
    auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
    if (record != st.end()) { // if record found
      st.erase(record);
    }
    //updte dist
    dist[neighbour.first] = nodedistance + neighbour.second;
    st.insert(make_pair(dist[neighbour.first],neighbour.first));
}
    }
    }
    return dist;
}
