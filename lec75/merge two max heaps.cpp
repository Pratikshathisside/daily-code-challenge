class Solution{
    private:
    void heapify(vector<int> &arr, int n, int i){
        int right = 2*i +1;
        int left = 2*i +2;
        int lar=i;
        if(right <n && arr[right]>arr[lar]){
            lar = right;
        }
        if(left <n &&arr[left]>arr[lar]){
            lar = left;
        }
        if(i!=lar){
            swap(arr[lar], arr[i]);
            heapify(arr,n,lar);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>ans1;
        for(auto i:a){
            ans1.push_back(i);
        }
        for(auto i:b){
            ans1.push_back(i);
        }
        //building heap from this
        int size = ans1.size();
        for(int i = size/2 -1; i>=0; i-- ){
            heapify(ans1,size,i);
        }
        return ans1;
    }
};
