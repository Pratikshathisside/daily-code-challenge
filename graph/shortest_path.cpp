#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int,list<int>> adj;
	// Write your code here
	//lets create adj list
	for(int i = 0; i<edges.size();i++){
		int u = edges[i].first;
		int v = edges[i].second;
adj[u].push_back(v);
adj[v].push_back(u);

	}
	//do bfs
	unordered_map<int,bool>visited;
	unordered_map<int,int>parent;
	queue<int>q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		for(auto i:adj[front]){
			if(!visited[i]){
visited[i]=1;
parent[i]=front;
q.push(i);
			}
		}	
	}
	vector<int>ans;
	int curr = t;
	ans.push_back(t);
	while(curr!=s){
        curr = parent[curr];
		ans.push_back(curr);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
