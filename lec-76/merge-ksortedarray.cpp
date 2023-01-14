#include<algorithm>
#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int,vector<int>,greater<int>>minheap;
    vector<int>sumStore;
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
             if(minheap.size()<k)
                 minheap.push(sum);
            else{
                if(sum>minheap.top()){
                    minheap.pop();
                    minheap.push(sum);
                }
            }
        }
       
    }
    
    return minheap.top();
}
