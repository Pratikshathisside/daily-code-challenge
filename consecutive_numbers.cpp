class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        map<int,int>m;
        int count  = 0;
        if(n ==0){
            return -1;
        }
       
        for(int i = 0; i<n ; i++){
            int val = k-arr[i];
            if(m[val]){
                count = count+m[val];
            }
            m[arr[i]]++;
            }
        return count;
        
    }
};
