class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int sum = 0;
        int fi=INT_MIN;
        vector<int>now;
      sort(nums.begin(),nums.end());
      
      for(int i = 0;i<nums.size()/2; i++){
          sum  = nums[i]+nums[nums.size()-i-1];
          fi=max(fi,sum);

      }
      
       return fi; 

    
    }
};
