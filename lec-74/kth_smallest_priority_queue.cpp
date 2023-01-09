class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        //using priority queue here
        priority_queue<int> pq;
        int i;
        for(i = 0; i<k; i++) {
            pq.push(arr[i]);
        }
        for(int j = k; j<=r;j++){
        if(arr[j]<pq.top()){
            pq.pop();
            pq.push(arr[j]);
           
            
        }}
        return pq.top();    
        
    }
};
