#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<algorithm>
#include<array>



int cmp(vector<int>&a,vector<int>&b){
  return a[2]<b[2];
}
void makeset(vector<int>&parent, vector<int>&rank,int n){

  for (int i = 0; i < n; i++) {
    rank[i] = 0;
    parent[i] = i;
  }
}
int findparent(vector<int>&parent,int node){
   //base case
   if(parent[node]==node){
     return node;
   }

  
    return  parent[node] = findparent(parent, parent[node]);
  
  
}
void makeunion(int u ,int v,vector<int>&parent,vector<int>&rank){
 
  u = findparent(parent,u);
 v = findparent(parent,v);
   if(rank[u]<rank[v]){
    parent[u]=v;
    // rank[v]++;
  }
  else if(rank[u]>rank[v]){
    parent[v]=u;
    // rank[u]++;
  }
  else{
    parent[u]=v;
    rank[v]++;
  }
}



int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  //sorting the array according to its weight in ascending order
  sort(edges.begin(),edges.end(),cmp);
  vector<int> parent(n);
  vector<int> rank(n);
  makeset(parent,rank,n);
  int minweight = 0;
  for(int i = 0; i<edges.size();i++){
    int u  =findparent(parent,edges[i][0]);
    int v = findparent(parent,edges[i][1]);
    int wt = edges[i][2];
    if(u!=v){
      minweight+=wt;
      makeunion(u,  v, parent, rank);
    }
  }
return minweight;
}
