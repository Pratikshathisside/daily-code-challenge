class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL)
            return NULL;
        
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left , p , q);
        
        else if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right , p , q);
        
        else
            return root;
    }
};
