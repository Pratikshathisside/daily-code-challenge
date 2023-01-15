#include <bits/stdc++.h> 
class node{
    public:
    int data; int row;
    int col;
    node(int data,int row,int col){
        this->data = data;
        this->row = row;
        this->col = col;
        
        
    }
};
class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data>b->data;
    }
    
}
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node* , vector<node*>,compare>minheap;
    for(int i =0; i<k;i++){
        node* temp = new node(kArrays[i][0],i,0)
        minheap.push(temp);
    }
    vector<int>ans;
    while(minheap.size()>0){
        node* tmp = minheap.top();
        minheap.pop();
        ans.push_back(tmp);
        int i = tmp->row;
        int j = tmp->col;
        if(j+1<KArrays[i].size()){
            node* next = new node(kArrays[i][j+1],i,j+1);
            minheap.push(next);
        }
    }
    return ans;
}
