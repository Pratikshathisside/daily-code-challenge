class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int m=1;
        for(int i=0;i<nums.size();i++)
        {
            m*=nums[i];
            ans=max(ans,m);
            if(m==0) m=1;
        }
        int n=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            n*=nums[i];
            ans=max(ans,n);
            if(n==0) n=1;
        }
        return ans;
    }
};
