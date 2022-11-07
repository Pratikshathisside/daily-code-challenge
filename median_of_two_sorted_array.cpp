class Solution {
    private:
    vector<int> merge(vector<int>&arr1, vector<int>&arr2){
    
        vector<int>marr;
        
            for(int i = 0;i<arr1.size();i++){
                marr.push_back(arr1[i]);
                
            }
        for(int j = 0; j<arr2.size(); j++){
            marr.push_back(arr2[j]);
        }
        sort(marr.begin(), marr.end());
        return marr;
        }  
    double check(vector<int>&arr){
        double  mid;
        double n = arr.size();
        if(arr.size()&1){
            mid = arr[(n-1)/2];
        }
        else{
            mid = double( (arr[n/2]+ arr[(n-2)/2]))/2;
        }
        return mid;
        
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> trying = merge(nums1, nums2);
        double ans = check (trying);
        return ans;
    }
};
