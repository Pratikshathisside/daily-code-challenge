class Solution {
    private:
    void inorder(TreeNode* root, vector<int>&in){
        if(root == NULL){
            return;
        }
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorderval;
        inorder(root,inorderval);
        int i = 0;
        int j = inorderval.size()-1;
        while(i<j){
            int sum = inorderval[i]+inorderval[j];
            if(sum==k){
                return true;
            }
            if(sum>k){
                j--;
            }
            if(sum<k){
                i++;
            }
        }
        return false;
    }
};
