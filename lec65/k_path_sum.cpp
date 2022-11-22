class Solution {
    private:
    void solve(TreeNode* root, int k, int &count, vector<int>path){
        //base case
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        //left traversal
        solve(root->left , k,count,path);
        //right
        solve(root->right, k, count, path);
        //check for k-sum
        int size = path.size();
        long long sum = 0;
        for (int i= size-1;i>=0; i--){
            sum+=path[i];
            if(sum==k){
                count++;
            }
          
            
            
            }
          path.pop_back();
        
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        vector<int>path;
        
        solve(root,targetSum,count,path);
        return count;
    }
};
