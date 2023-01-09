class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
  
    priority_queue<int,vector<int>,greater<int>> pq;
        int i;
        for(i = 0; i<k; i++) {
            pq.push(nums[i]);
        }
        for(int j = k; j<nums.size();j++){
        if(nums[j]>pq.top()){
            pq.pop();
            pq.push(nums[j]);
           
            
        }}
        return pq.top();    

        
    }
};
