class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL){
            return NULL;
        }
        if(root ==p || root ==q){
            return root;
        }
        TreeNode* leftans = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans = lowestCommonAncestor(root->right,p,q);
        if(leftans!=NULL && rightans!=NULL){
            return root;
        }
        else if(leftans!=NULL && rightans ==NULL){
            return leftans;
        }
        else if (leftans == NULL && rightans!=NULL){
            return rightans;
        }
        else
            return NULL;
    }
};
